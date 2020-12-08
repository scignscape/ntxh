///////////////////////////////////////////////////////////////////////////////
//
// 3DimViewer
// Lightweight 3D DICOM viewer.
//
// Copyright 2008-2016 3Dim Laboratory s.r.o.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// include files
#include <graph/osg/CSprite.h>
#include <osg/CullStack>
#include <osgViewer/ViewerEventHandlers>
#include <osg/Version>
#include "osg/CSceneOSG.h"
#include <osg/SimpleShader.h>



osg::CAdvSprite::CAdvSprite(osg::Texture2D *texture, osg::Vec2 pivotPoint)
    : _scale(1.0f, 1.0f, 1.0f)
    , _firstTimeToInitEyePoint(true)
    , _previousWidth(0)
    , _previousHeight(0)
    , _matrixDirty(true)
    , _side(1.0f, 0.0f, 0.0f)
    , _pivotPoint(pivotPoint)
    , _centerOffsetX(0.0)
    , _centerOffsetY(0.0)
    , _centerOffsetZ(0.0)
{
    assert(texture != NULL);

    this->setCullingActive(false);

    _quad = osg::createTexturedQuadGeometry(osg::Vec3(0.0f, 0.0f, 0.0f), osg::Vec3(1.0f, 0.0f, 0.0f), osg::Vec3(0.0f, 1.0f, 0.0f), 1.0f, 1.0f);
    osg::ref_ptr<osg::Geode> geode = new osg::Geode;
    geode->addDrawable(_quad);
    texture->setResizeNonPowerOfTwoHint(false);
    texture->setFilter(osg::Texture::MIN_FILTER, osg::Texture::LINEAR);
    texture->setWrap(osg::Texture::WRAP_S, osg::Texture::CLAMP_TO_EDGE);
    texture->setWrap(osg::Texture::WRAP_T, osg::Texture::CLAMP_TO_EDGE);

    addChild(geode);

    osgViewer::InteractiveImageHandler *handler = new osgViewer::InteractiveImageHandler(texture->getImage());

    auto shader = new osg::Program();
    shader->addShader(new osg::Shader(osg::Shader::VERTEX, texturedShaderVert));
    shader->addShader(new osg::Shader(osg::Shader::FRAGMENT, texturedShaderFrag));

    geode->getOrCreateStateSet()->setMode(GL_BLEND, osg::StateAttribute::ON);
    geode->getOrCreateStateSet()->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
    geode->getOrCreateStateSet()->setNestRenderBins(false); // we really REALLY want to separate this layer at the top
    geode->getOrCreateStateSet()->setRenderBinDetails(LAYER_GIZMOS - 1, "RenderBin");
    geode->getOrCreateStateSet()->setTextureAttributeAndModes(0, texture, osg::StateAttribute::ON);
    geode->getOrCreateStateSet()->addUniform(new osg::Uniform("texSampler", 0));
    geode->getOrCreateStateSet()->setAttributeAndModes(shader, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE | osg::StateAttribute::PROTECTED);

    _quad->setEventCallback(handler);
    _quad->setCullCallback(handler);

    _spriteWidth = texture->getImage()->s();
    _spriteHeight = texture->getImage()->t();
}

bool osg::CAdvSprite::computeLocalToWorldMatrix(Matrix &matrix, NodeVisitor *nv) const
{
    if (_matrixDirty)
    {
        computeMatrix();
    }
    matrix.preMult(_cachedMatrix);
    return true;
}

bool osg::CAdvSprite::computeWorldToLocalMatrix(Matrix &matrix, NodeVisitor *nv) const
{
    if (_matrixDirty)
    {
        computeMatrix();
    }
    matrix.postMult(osg::Matrix::inverse(_cachedMatrix));
    return true;
}

void osg::CAdvSprite::computeMatrix() const
{
    if (!_matrixDirty)
    {
        return;
    }

    _cachedMatrix = _matrix;

    _matrixDirty = false;
}

void osg::CAdvSprite::accept(NodeVisitor &nv)
{
    if (!nv.validNodeMask(*this))
    {
        return;
    }

    // if app traversal update the frame count.
    if (nv.getVisitorType() == NodeVisitor::CULL_VISITOR)
    {
        osg::CullStack *cs = dynamic_cast<osg::CullStack *>(&nv);
        if (cs != NULL)
        {
            Viewport::value_type width = _previousWidth;
            Viewport::value_type height = _previousHeight;
            int iWidth = width;
            int iHeight = height;

            osg::Viewport *viewport = cs->getViewport();
            if (viewport)
            {
                iWidth = width = viewport->width();
                iHeight = height = viewport->height();
            }

            osg::Vec2 offset;
            if (iWidth % 2 != _spriteWidth % 2)
            {
                offset[0] = 0.5 / iWidth;
            }
            if (iHeight % 2 != _spriteHeight % 2)
            {
                offset[1] = 1.0 / iHeight;
            }

            const osg::Matrix &projection = *(cs->getProjectionMatrix());
            const osg::Matrix &modelview = *(cs->getModelViewMatrix());

            _matrix = osg::Matrix::identity();
            _matrix *= osg::Matrix::translate(-0.5 + offset[0], -0.5 + offset[1], -1.0);
            _matrix *= osg::Matrix::translate(_centerOffsetX*2.0, _centerOffsetY*2.0, _centerOffsetZ*2.0); // multiplied by 2.0 because of projection space
            _matrix *= osg::Matrix::scale(2.0 / projection(0, 0), 2.0 / projection(1, 1), 1.0);
            _matrix *= osg::Matrix::scale(_spriteWidth / width, _spriteHeight / height, 1.0);
            _matrix *= osg::Matrixd::inverse(modelview);

            _previousWidth = width;
            _previousHeight = height;

            _matrixDirty = true;
        }
    }

    // now do the proper accept
    Transform::accept(nv);
}

osg::BoundingSphere osg::CAdvSprite::computeBound() const
{
    BoundingSphere bsphere = Transform::computeBound();
    //bsphere.set(bsphere.center(), 100.0f);
    return bsphere;
}

void osg::CAdvSprite::setOffsetFromCenter(double dx, double dy, double dz)
{
    if (dx >= 0.0 && dx <= 1.0)
        _centerOffsetX = dx;
    if (dy >= 0.0 && dy <= 1.0)
        _centerOffsetY = dy;
    if (dz >= 0.0 && dz <= 1.0)
        _centerOffsetZ = dz;
}

void osg::CAdvSprite::setPosition(const Vec3d &pos)
{
    _position = pos;
    _matrixDirty = true;
    dirtyBound();
}

const osg::Vec3d &osg::CAdvSprite::getPosition() const
{
    return _position;
}

void osg::CAdvSprite::setColor(const Vec4 &color)
{
    _color = color;
    osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;
    colors->push_back(_color);
	_quad->setColorArray(colors, osg::Array::BIND_OVERALL);
}

osg::Vec4 osg::CAdvSprite::getColor() const
{
    return _color;
}

void osg::CAdvSprite::setRotation(const Quat& quat)
{
    _rotation = quat;
    _matrixDirty = true;
    dirtyBound();
}

const osg::Quat &osg::CAdvSprite::getRotation() const
{
    return _rotation;
}

void osg::CAdvSprite::setScale(const Vec3d &scale)
{
    _scale = scale;
    _matrixDirty = true;
    dirtyBound();
}

void osg::CAdvSprite::setScale(double scale)
{
    setScale(osg::Vec3(scale, scale, scale));
}

const osg::Vec3d &osg::CAdvSprite::getScale() const
{
    return _scale;
}


///////////////////////////////////////////////////////////////////////////////
//
osg::CSprite::CSpriteComputeBoundingBoxCallback::CSpriteComputeBoundingBoxCallback(CSprite *sprite)
{
    if (NULL != sprite && NULL != sprite->m_texture.get() && NULL != sprite->m_texture->getImage()) // happened when png library was missing
    {
        int w = sprite->m_texture->getImage()->s();
        int h = sprite->m_texture->getImage()->t();
        int d = w + h / 2;
        m_boundingBox = osg::BoundingBox(osg::Vec3(-w / 2, -h / 2, -d / 2), osg::Vec3(w / 2, h / 2, d / 2));
    }
    else
    {
        m_boundingBox.init();        
#ifdef _WIN32
        OutputDebugStringA("invalid sprite in CSpriteComputeBoundingBoxCallback");
#endif
    }
}

///////////////////////////////////////////////////////////////////////////////
//
osg::BoundingBox osg::CSprite::CSpriteComputeBoundingBoxCallback::computeBound(const osg::Drawable &drawable) const
{
    return m_boundingBox;
}

osg::CSprite::CSprite(osg::Texture2D *texture, osg::Vec3 position, bool absolutePosition, osg::MatrixTransform *matrix, osg::Vec4 color, osg::Vec2 scale, osg::BlendFunc *blendFunc, osg::Depth *depth)
    : m_absolutePosition(absolutePosition)
    , m_texture(texture)
    , m_position(position)
    , m_scale(scale)
    , m_color(color)
    , m_depth(depth)
    , m_blend(blendFunc)
    , m_matrix(matrix)
{
    if (m_depth == nullptr)
    {
        m_depth = new osg::Depth(osg::Depth::ALWAYS);
        m_depth->setWriteMask(false);
    }

    if (m_blend == nullptr)
    {
        m_blend = new osg::BlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }

    auto shader = new osg::Program();
    shader->addShader(new osg::Shader(osg::Shader::VERTEX, texturedShaderVert));
    shader->addShader(new osg::Shader(osg::Shader::FRAGMENT, texturedShaderFrag));

    getOrCreateStateSet()->setTextureAttributeAndModes(0, m_texture, osg::StateAttribute::ON);
    getOrCreateStateSet()->setAttributeAndModes(m_blend, osg::StateAttribute::ON);
    getOrCreateStateSet()->setAttributeAndModes(m_depth, osg::StateAttribute::ON);
    getOrCreateStateSet()->addUniform(new osg::Uniform("texSampler", 0));
    getOrCreateStateSet()->setAttributeAndModes(shader, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE | osg::StateAttribute::PROTECTED );

    createGeometry();

    setCullCallback(new osg::CPreventCullCallback());
    setComputeBoundingBoxCallback(new osg::CSprite::CSpriteComputeBoundingBoxCallback(this));
    computeBound();
}

osg::CSprite::CSprite(osg::Texture2D *texture, osg::MatrixTransform *matrix, osg::Vec4 color, osg::Vec2 scale, osg::BlendFunc *blendFunc, osg::Depth *depth)
    : CSprite(texture, osg::Vec3(0.0f, 0.0f, 0.0f), false, matrix, color, scale, blendFunc, depth)
{

}


//////////////////////////////////////////////////////////////////////////
//
osg::CSprite::CSprite(const CSprite& sprite)
    : CSprite(sprite.m_texture, sprite.m_position, sprite.m_absolutePosition, sprite.m_matrix, sprite.m_color, sprite.m_scale, sprite.m_blend, sprite.m_depth)
{

}

///////////////////////////////////////////////////////////////////////////////
//
void osg::CSprite::drawImplementation(osg::RenderInfo &renderInfo) const
{
    osg::State *state = renderInfo.getState();
    osg::Camera *camera = renderInfo.getCurrentCamera();
    
    osg::Matrix windowMatrix = camera->getViewport()->computeWindowMatrix();
    osg::Matrix projectionMatrix = camera->getProjectionMatrix();
    osg::Matrix projectionMatrixInv = osg::Matrix::inverse(camera->getProjectionMatrix());
    osg::Matrix viewMatrix = osg::Matrix::identity();
    osg::Matrix modelMatrix = osg::Matrix::identity();
    osg::Matrix modelViewMatrix = state->getModelViewMatrix();
    osg::Matrix modelViewMatrixInv = osg::Matrix::inverse(state->getModelViewMatrix());
    osg::Matrix m = modelViewMatrix * projectionMatrix * windowMatrix;

    // calculate position if necessary
    osg::Vec3 position = m_position;
    if (!m_absolutePosition)
    {
        position += osg::Vec3(0.0f, 0.0f, 0.0f) * m;
    }

    projectionMatrix = osg::Matrix::identity();
    viewMatrix = osg::Matrix::identity();
    modelMatrix = osg::Matrix::identity();

    osg::Vec2 windowDimensions = osg::Vec2(camera->getViewport()->width(), camera->getViewport()->height());
    osg::Vec2 textureDimensions = osg::Vec2(m_texture->getTextureWidth(), m_texture->getTextureHeight());

    // scale quad over entire screen (for easier manipulation)
    modelMatrix = osg::Matrix::scale(2.0, 2.0, 1.0) * osg::Matrix::translate(-1.0, -1.0, 0.0);

    position.x() = static_cast<int>(position.x());
    position.y() = static_cast<int>(position.y());
    position.z() = static_cast<int>(position.z());

    // translate quad to specified position
    osg::Vec3 screenPosition = osg::Vec3(position.x() / windowDimensions.x(), position.y() / windowDimensions.y(), 0.0);
    modelMatrix = osg::Matrix::translate(screenPosition.x(), screenPosition.y(), screenPosition.z()) * modelMatrix;

    // scale quad so that it has correct dimensions on screen
    modelMatrix = osg::Matrix::scale(m_scale.x() * textureDimensions.x() / windowDimensions.x(), m_scale.y() * textureDimensions.y() / windowDimensions.y(), 1.0) * modelMatrix;

    // apply calculated matrices
    state->applyProjectionMatrix(new osg::RefMatrix(projectionMatrix));
    state->applyModelViewMatrix(new osg::RefMatrix(modelMatrix * viewMatrix));
    state->applyModelViewAndProjectionUniformsIfRequired();

    if (m_matrix != NULL)
    {
        m_matrix->setMatrix(modelMatrix * viewMatrix * projectionMatrix * projectionMatrixInv * modelViewMatrixInv);
    }
    
    // use standard rendering
    osg::Geometry::drawImplementation(renderInfo);
}


///////////////////////////////////////////////////////////////////////////////
//
void osg::CSprite::createGeometry()
{
    m_vertices = new osg::Vec3Array;
    m_vertices->push_back(osg::Vec3(0.0f, 0.0f, 0.0f));
    m_vertices->push_back(osg::Vec3(1.0f, 0.0f, 0.0f));
    m_vertices->push_back(osg::Vec3(0.0f, 1.0f, 0.0f));
    m_vertices->push_back(osg::Vec3(1.0f, 1.0f, 0.0f));

    m_colors = new osg::Vec4Array;
    m_colors->push_back(m_color);

    m_texCoords = new osg::Vec2Array;
    m_texCoords->push_back(osg::Vec2(0.0f, 0.0f));
    m_texCoords->push_back(osg::Vec2(1.0f, 0.0f));
    m_texCoords->push_back(osg::Vec2(0.0f, 1.0f));
    m_texCoords->push_back(osg::Vec2(1.0f, 1.0f));

    setVertexArray(m_vertices);
	setColorArray(m_colors, osg::Array::BIND_OVERALL);
    setTexCoordArray(0, m_texCoords);
    addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::TRIANGLE_STRIP, 0, 4));
}

///////////////////////////////////////////////////////////////////////////////
//
osg::CSpriteNode::CSpriteNode(osg::CSprite *sprite)
{
    setName("CSpriteNode");
    m_sprite = sprite;
    addDrawable(m_sprite);
}


///////////////////////////////////////////////////////////////////////////////
//
osg::CSpriteNode::CSpriteNode(const CSpriteNode &spriteNode) : osg::Geode()
{
    setName("CSpriteNode");
    m_sprite = new CSprite(*spriteNode.m_sprite);
    addDrawable(m_sprite);
}

///////////////////////////////////////////////////////////////////////////////
//
osg::CSpriteShadow::CSpriteShadow(ESpriteShadowType type, osg::Depth *depth)
{
    m_depth = depth;
    m_type = type;

    if (m_depth == NULL)
    {
        m_depth = new osg::Depth;
        m_depth->setFunction(osg::Depth::ALWAYS);
        m_depth->setWriteMask(false);
    }

    m_stateSet = getOrCreateStateSet();
    m_stateSet->setAttributeAndModes(m_depth, osg::StateAttribute::ON);

    createGeometry();

    setCullCallback(new osg::CForceCullCallback(true));
}


//////////////////////////////////////////////////////////////////////////
//
osg::CSpriteShadow::CSpriteShadow(const CSpriteShadow &shadow) : osg::Geometry()
{
    m_depth = shadow.m_depth;
    m_type = shadow.m_type;

    m_depth = new osg::Depth;
    m_depth->setFunction(osg::Depth::ALWAYS);
    m_depth->setWriteMask(false);

    m_stateSet = getOrCreateStateSet();
    m_stateSet->setAttributeAndModes(m_depth, osg::StateAttribute::ON);

    createGeometry();
}

///////////////////////////////////////////////////////////////////////////////
//
void osg::CSpriteShadow::createGeometry()
{
    switch (m_type)
    {
    case ESST_DEFAULT:
        m_vertices = new osg::Vec3Array;
        m_vertices->push_back(osg::Vec3(0.0f, 0.0f, 0.0f));
        m_vertices->push_back(osg::Vec3(1.0f, 0.0f, 0.0f));
        m_vertices->push_back(osg::Vec3(0.0f, 1.0f, 0.0f));
        m_vertices->push_back(osg::Vec3(1.0f, 1.0f, 0.0f));

        m_indices = new DrawElementsUInt(GL_TRIANGLES, 6);
        m_indices->push_back(0);
        m_indices->push_back(1);
        m_indices->push_back(2);
        m_indices->push_back(1);
        m_indices->push_back(3);
        m_indices->push_back(2);

        break;
    case ESST_IMPLANT_INVALID:
        m_vertices = new osg::Vec3Array;
        m_vertices->push_back(osg::Vec3(0.25f, 0.0f, 0.0f));
        m_vertices->push_back(osg::Vec3(0.75f, 0.0f, 0.0f));
        m_vertices->push_back(osg::Vec3(0.0f, 0.25f, 0.0f));
        m_vertices->push_back(osg::Vec3(1.0f, 0.25f, 0.0f));
        m_vertices->push_back(osg::Vec3(0.0f, 0.75f, 0.0f));
        m_vertices->push_back(osg::Vec3(1.0f, 0.75f, 0.0f));
        m_vertices->push_back(osg::Vec3(0.25f, 1.0f, 0.0f));
        m_vertices->push_back(osg::Vec3(0.75f, 1.0f, 0.0f));

        m_indices = new DrawElementsUInt(GL_TRIANGLE_STRIP, 8);
        m_indices->push_back(0);
        m_indices->push_back(1);
        m_indices->push_back(2);
        m_indices->push_back(3);
        m_indices->push_back(4);
        m_indices->push_back(5);
        m_indices->push_back(6);
        m_indices->push_back(7);

        break;
    default:
        break;
    }

    setVertexArray(m_vertices);
    addPrimitiveSet(m_indices);
}


///////////////////////////////////////////////////////////////////////////////
//
osg::CSpriteShadowNode::CSpriteShadowNode(osg::CSpriteShadow *shadow)
{
    setName("CSpriteShadowNode");
    m_shadow = shadow;
    m_shadowGeode = new osg::Geode();
    addChild(m_shadowGeode);
    m_shadowGeode->addDrawable(m_shadow);
}


///////////////////////////////////////////////////////////////////////////////
//
osg::CSpriteShadowNode::CSpriteShadowNode(const CSpriteShadowNode &shadowNode) : MatrixTransform()
{
    setName("CSpriteShadowNode");
    m_shadow = new CSpriteShadow(*shadowNode.m_shadow);
    m_shadowGeode = new osg::Geode(*shadowNode.m_shadowGeode);
    addChild(m_shadowGeode);
    m_shadowGeode->addDrawable(m_shadow);
}

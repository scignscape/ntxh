////////////////////////////////////////////////////////////
// $Id: mctris.cpp 1863 2010-08-31 20:40:15Z spanel $
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// includes

#include <VectorEntity/mctris.h>
#include <VectorEntity/mcedge.h>
#include <VectorEntity/mcsphere.h>

#include <time.h>

using namespace vctl;

////////////////////////////////////////////////////////////
//

MCTri * MCTriS::New(MCVertex * _u0, MCVertex * _u1, MCVertex * _u2)
{
    MCTri          * new_tri;          // ukazatel na nove tri

    assert((_u0 != NULL) && (_u1 != NULL) && (_u2 != NULL));

    // test existence tri danych uzlu
    if ((new_tri = TestExistence(_u0, _u1, _u2)) == NULL)
    {
        // vytvoreni noveho objektu tri
        new_tri = new MCTri(_u0, _u1, _u2);
        // vlozeni noveho tri do retezu
        AddNode(new_tri);
        // registrace noveho tri u jejich uzlu
        new_tri->Registration();
    }

    return new_tri;
}

////////////////////////////////////////////////////////////
//

void MCTriS::Erase( MCTri * del_ent)
{
    assert(del_ent != NULL);

    // vyhozeni entity z retezce
    EraseNode(del_ent);

    // uvolneni vazeb entity u jejich node
    del_ent->DeRegistration();

    // zruseni objektu dane entity
    delete(del_ent);
}

////////////////////////////////////////////////////////////
//

void MCTriS::DeRegistrationAll()
{
    MCTri        * actual = GetFirst();      // ukazatel na aktualni entitu


    // zruseni vsech existujicich entit s uvolnovanim vazeb
    while (actual != NULL)
    {
        // odregistrovani aktualniho Tri z jeho vrcholu
        actual->DeRegistration();
        // ziskani nasledujici entity
        actual = actual->GetNext();
    }
}

////////////////////////////////////////////////////////////
//

void MCTriS::GetTriEdge( MCVertex * _u0, MCVertex * _u1, std::vector<MCTri *> & tri_pole )
{
    assert((_u0 != NULL) && (_u1 != NULL));

    MCTri      * actual = _u0->GetRegisteredTri();            // ukazatel na aktualni tri kolem prvniho uzlu hrany

    // vyprazdneni pole pro tri
    tri_pole.clear();

    // cyklus tri kolem prvniho uzlu dane hrany
    while (actual != NULL)
    {
        // test aktual, jestli obsahuje druhy uzel hrany
        if (actual->IsVertexBool(_u1))
            tri_pole.push_back(actual);      // pridani aktual do fronty tri

        // ziskani dalsiho tri podilejiciho se na prvnim uzlu dane hrany
        actual = actual->GetVertexTri(_u0);
    }
}

////////////////////////////////////////////////////////////
//

int MCTriS::GetTriEdgeNumber( MCVertex * _u0, MCVertex * _u1)
{
    assert((_u0 != NULL) && (_u1 != NULL));

    MCTri      * actual = _u0->GetRegisteredTri();            // ukazatel na aktualni tri kolem prvniho uzlu hrany
    int        poc_tri = 0;                              // pocet tri hrany

    // cyklus tri kolem prvniho uzlu dane hrany
    while (actual != NULL)
    {
        // test aktual, jestli obsahuje druhy uzel hrany
        if (actual->IsVertexBool(_u1))
            poc_tri++;

        // ziskani dalsiho tri podilejiciho se na prvnim uzlu dane hrany
        actual = actual->GetVertexTri(_u0);
    }

    return poc_tri;
}

////////////////////////////////////////////////////////////
//

bool MCTriS::TestEdgeExistence( MCVertex * _u0, MCVertex * _u1 )
{
    assert((_u0 != NULL) && (_u1 != NULL));

    MCTri      * actual = _u0->GetRegisteredTri();            // ukazatel na tri zdilejici prvni uzel hrany

    // cyklus tri kolem prvniho uzlu dane hrany
    while (actual != NULL)
    {
        // test jestli aktualni tri obsahuje druhy uzel hrany
        if (actual->IsVertexBool(_u1))
            return true;                // hrana existuje

        // ziskani dalsiho tri podilejiciho se na prvnim uzlu dane hrany
        actual = actual->GetVertexTri(_u0);
    }

    // hrana neexistuje
    return false;
}

////////////////////////////////////////////////////////////
//

MCTri * MCTriS::TestExistence(MCVertex * _u0, MCVertex * _u1, MCVertex * _u2)
{
    assert((_u0 != NULL) && (_u1 != NULL) && (_u2 != NULL));

    MCTri      * actual = _u0->GetRegisteredTri();            // ukazatel na tri zdilejici prvni uzel hrany

    // cyklus tri kolem prvniho uzlu dane hrany
    while (actual != NULL)
    {
        // test jestli aktualni tri obsahuje druhy a treti uzel daneho tri
        if (actual->IsVertexBool(_u1) && actual->IsVertexBool(_u2))
            return actual;                // tri existuje

        // ziskani dalsiho tri podilejiciho se na prvnim uzlu dane hrany
        actual = actual->GetVertexTri(_u0);
    }

    // tri neexistuje
    return NULL;
}

////////////////////////////////////////////////////////////
//

bool MCTriS::TestManifold()
{
    MCTri        * actual = GetFirst();          // ukazatel na aktualni tri


    // cyklus tri
    while (actual != NULL)
    {
        // testy pocty tri kolem hran aktualniho tri
        if (GetTriEdgeNumber(actual->GetVertex(0), actual->GetVertex(1)) != 2)
            return false;
        if (GetTriEdgeNumber(actual->GetVertex(1), actual->GetVertex(2)) != 2)
            return false;
        if (GetTriEdgeNumber(actual->GetVertex(2), actual->GetVertex(0)) != 2)
            return false;

        // ziskani dalsi tri v poradi
        actual = actual->GetNext();
    }

    return true;
}

////////////////////////////////////////////////////////////
//

void MCTriS::MakeAllTrisEdges()
{
    MCTri									* actual = GetFirst();					        // ukazatel na aktualni tri site


    // cyklus tri site
    while (actual != NULL)
    {
        // vytvoreni hran aktualniho tri
        MakeTriEdges(actual);
        // ziskani nasledujiciho tri retezce
        actual = actual->GetNext();
    }
}

////////////////////////////////////////////////////////////
//

void MCTriS::MakeTriEdges(MCTri * _tri)
{
    // test existence daneho tri
    assert(_tri != NULL);

    // vytvoreni hran daneho tri
    edges.New(_tri->GetVertex(0), _tri->GetVertex(1));
    edges.New(_tri->GetVertex(1), _tri->GetVertex(2));
    edges.New(_tri->GetVertex(2), _tri->GetVertex(0));
}

////////////////////////////////////////////////////////////
//

void MCTriS::EraseEdgesNoTris()
{
    MCEdge					* actual = edges.GetFirst();					        // ukazatel na aktualni hranu site
    MCEdge          * to_erase;                                   // ukazatel na hranu urcenou k vymazani


    // cyklus hran site
    while (actual != NULL)
    {
        // ziskani a test poctu tri aktualni hrany
        if (GetTriEdgeNumber(actual->GetVertex(0), actual->GetVertex(1)) == 0)
        {
            // ulozeni ukazatel na hranu urcenou k vymazani
            to_erase = actual;
            // ziskani nasledujici hrany retezce
            actual = actual->GetNext();
            // vymazani hrany retezce, ktera nezdili zadne tri
            edges.Erase(to_erase);
        }
        else
            // ziskani nasledujici hrany retezce
            actual = actual->GetNext();
    }
}

////////////////////////////////////////////////////////////
//

bool MCTriS::LoadSTL(mds::mod::CChannel& Channel)
{
    const mds::tSize HEADER_SIZE = 80; // size of binary STL header
    const mds::tSize BUFFER_SIZE = 1024; // size of temporary read buffer
    char file_header[HEADER_SIZE]; // STL file header array

    // given channel testing
    if ( ! Channel.isConnected())
      return false;

    // clear container from existing entities
    ClearAll();

    // file header loading
    if (Channel.read( (char *) file_header, HEADER_SIZE) != HEADER_SIZE)
    {
      return false;
    }

    // check for binary or ASCII format
    if (!strncmp(file_header, "solid", sizeof("solid") - 1))
    {
      // input buffer
      char buffer[BUFFER_SIZE];
      memcpy(buffer, file_header, HEADER_SIZE);
      mds::tSize buffer_start = 0;
      mds::tSize buffer_end = HEADER_SIZE;

      // state variables
      STLState state = STATE_INIT;
      float vector[3];
      int vector_index = 0;
      MCVertex * face[3];
      int face_index = 0;

      while (true)
      {
        STLToken token;

        if (state != STATE_FINISH)
        {
          token = this->getSTLToken(buffer, buffer_start, buffer_end);
        }

        if (token.type == TOKEN_UNKNOWN)
        {
          // move data left to front of the buffer and read data to the rest
          mds::tSize buffer_left = buffer_end - buffer_start;
          memmove(buffer, buffer + buffer_start, buffer_left);
          mds::tSize bytes_read = Channel.read(buffer + buffer_left,
            BUFFER_SIZE - buffer_left);

          // update buffer pointers
          buffer_start = 0;
          buffer_end = BUFFER_SIZE;

          // restart parsing
          if (bytes_read != 0)
          {
            continue;
          }
        }

        switch (state)
        {
          case STATE_INIT:
          {
            // enable vertices existence test
            this->vertices->SetTestExistence(true);

            if (token.type == TOKEN_SOLID)
            {
              state = STATE_SOLID;
            }
            else
            {
              // unexpected token
              return false;
            }
          }
          break;
          case STATE_SOLID:
          {
            switch (token.type)
            {
              case TOKEN_IDENTIFIER:
              {
                state = STATE_INSOLID;
              }
              break;
              default:
              {
                // unexpected token
                return false;
              }
            }
          }
          break;
          case STATE_INSOLID:
          {
            switch (token.type)
            {
              case TOKEN_FACET:
              {
                state = STATE_FACET;
              }
              break;
              case TOKEN_ENDSOLID:
              {
                state = STATE_ENDSOLID;
              }
              break;
              default:
              {
                // unexpected token
                return false;
              }
            }
          }
          break;
          case STATE_FACET:
          {
            if (token.type == TOKEN_NORMAL)
            {
              // start reading normal
              vector[0] = vector[1] = vector[2] = 0.0f;
              vector_index = 0;
              state = STATE_NORMAL;
            }
            else
            {
              // unexpected token
              return false;
            }
          }
          break;
          case STATE_NORMAL:
          {
            switch (token.type)
            {
              case TOKEN_NUMBER:
              {
                // convert normal coordinate token to floating number
                vector[vector_index] = float(atof(buffer + token.begin));
                vector_index++;
              }
              break;
              case TOKEN_OUTER:
              {
                // NOTE: normals are not used anyhow
                state = STATE_OUTER;
              }
              break;
              default:
              {
                // unexpected token
                return false;
              }
            }
          }
          break;
          case STATE_INFACET:
          {
            switch (token.type)
            {
              case TOKEN_OUTER:
              {
                state = STATE_OUTER;
              }
              break;
              case TOKEN_ENDFACET:
              {
                state = STATE_INSOLID;
              }
              break;
              default:
              {
                // unexpected token
                return false;
              }
            }
          }
          break;
          case STATE_OUTER:
          {
            if (token.type == TOKEN_LOOP)
            {
              state = STATE_INLOOP;
            }
            else
            {
              // unexpected token
              return false;
            }
          }
          break;
          case STATE_INLOOP:
          {
            switch (token.type)
            {
              case TOKEN_VERTEX:
              {
                // start first vertex of a face
                vector[0] = vector[1] = vector[2] = 0.0f;
                vector_index = 0;
                face_index = 0;
                state = STATE_VERTEX;
              }
              break;
              case TOKEN_ENDLOOP:
              {
                state = STATE_INFACET;
              }
              break;
              default:
              {
                // unexpected token
                return false;
              }
            }
          }
          break;
          case STATE_VERTEX:
          {
            switch (token.type)
            {
              case TOKEN_NUMBER:
              {
                // convert vertex coordinate token to floating number
                vector[vector_index] = float(atof(buffer + token.begin));
                vector_index++;
              }
              break;
              case TOKEN_VERTEX:
              {
                // finish vertex
                face[face_index] = vertices->New(vector[0], vector[1], vector[2]);
                face_index++;

                // start new one
                vector[0] = vector[1] = vector[2] = 0.0f;
                vector_index = 0;
              }
              break;
              case TOKEN_ENDLOOP:
              {
                // finish vertex
                face[face_index] = vertices->New(vector[0], vector[1], vector[2]);

                // finish face
                assert((face[0] != NULL) && (face[1] != NULL) && (face[2] != NULL));
                this->New(face[0], face[1], face[2]);
                state = STATE_INFACET;
              }
              break;
              default:
              {
                // unexpected token
                return false;
              }
            }
          }
          break;
          case STATE_ENDSOLID:
          {
            if (token.type == TOKEN_IDENTIFIER)
            {
              state = STATE_FINISH;
            }
            else
            {
              // unexpected token
              return false;
            }
          }
          break;
          case STATE_FINISH:
          {
            // disable vertices existence test
            this->vertices->SetTestExistence(false);

            // finished correctly
            return true;
          }
          break;
        }
      }
    }
    else
    {
      unsigned int        file_tri_number;               // number of tris saved in STL file
      unsigned short int  file_tri_attribute;            // STL tri attribute saved in file
      float               file_tri_n[3];                 // file tri normal coordinates array
      float               file_tri_v1[3];                // file tri vertex coordinates array
      float               file_tri_v2[3];                // file tri vertex coordinates array
      float               file_tri_v3[3];                // file tri vertex coordinates array
      MCVertex            * v1, * v2, * v3;              // new created vertices pointers

      // file tri number loading
      if (Channel.read( (char *) &file_tri_number, sizeof(file_tri_number)) != sizeof(file_tri_number))
        return false;

      // vertex existence switch on
      assert(vertices != NULL);
      vertices->SetTestExistence(true);

      // file tris reading cycle
      for (unsigned int t = 0; t < file_tri_number; ++t)
      {
        // file tri normal loading
        if (Channel.read( (char *) file_tri_n, (sizeof(float)*3)) != (sizeof(float)*3))
        {
          vertices->SetTestExistence(false);
          return false;
        }
        // file tri vertex v1 loading
        if (Channel.read( (char *) file_tri_v1, (sizeof(float)*3)) != (sizeof(float)*3))
        {
          vertices->SetTestExistence(false);
          return false;
        }
        // file tri vertex v2 loading
        if (Channel.read( (char *) file_tri_v2, (sizeof(float)*3)) != (sizeof(float)*3))
        {
          vertices->SetTestExistence(false);
          return false;
        }
        // file tri vertex v3 loading
        if (Channel.read( (char *) file_tri_v3, (sizeof(float)*3)) != (sizeof(float)*3))
        {
          vertices->SetTestExistence(false);
          return false;
        }
        // file tri attribute loading
        if (Channel.read( (char *) &file_tri_attribute, sizeof(file_tri_attribute)) != sizeof(file_tri_attribute))
        {
          vertices->SetTestExistence(false);
          return false;
        }

        // create new vertices by loaded coordinates
        v1 = vertices->New(file_tri_v1[0], file_tri_v1[1], file_tri_v1[2]);
        v2 = vertices->New(file_tri_v2[0], file_tri_v2[1], file_tri_v2[2]);
        v3 = vertices->New(file_tri_v3[0], file_tri_v3[1], file_tri_v3[2]);
        assert((v1 != NULL) && (v2 != NULL) && (v3 != NULL));
        // create new tri by loaded coordinates
        New(v1, v2, v3);
      }

      // tri number control
      //assert(GetNumber() == file_tri_number);

      // vertex existence switch off
      vertices->SetTestExistence(false);
    }

    return true;
}

////////////////////////////////////////////////////////////
//

bool MCTriS::SaveSTL(mds::mod::CChannel& Channel)
{
    char                file_heared[90];               // STL file header array
    unsigned int        file_tri_number;               // Number of tris saved in STL file
    unsigned short int  file_tri_attribute = 0;        // STL tri attribute saved in file
    MCTri               * actual = GetFirst();         // actual tri pointer
    MCVertex            * tri_vertices[3];             // atual tri vertices array
    MCVector3D          actual_tri_n;                  // actual tri normal
    float               actual_coordinates[3];         // actual coordinates of vector or vertex


    // given channel testing
    if ( ! Channel.isConnected())
      return false;

    // initialize file header
    memset(file_heared, 0, 85);
    // set file header text
    strcpy(file_heared, "Binary STL file created by conversion of TRI file format, MDSTk::VectEntity library");
    // write file header
    if ( ! Channel.write( (char *) file_heared, 80) )
      return false;

    // write file tri number
    file_tri_number = GetNumber();
    if ( ! Channel.write( (char *) &file_tri_number, sizeof(unsigned int)) )
      return false;

    // file tris writing cycle
    while (actual != NULL)
    {
        // take vertices of actual tri
        actual->GetVerticeS(tri_vertices);

        // take actual tri normal
        actual_tri_n = actual->GetNormal();
        actual_coordinates[0] = (float) actual_tri_n.GetX();
        actual_coordinates[1] = (float) actual_tri_n.GetY();
        actual_coordinates[2] = (float) actual_tri_n.GetZ();
        // write actual tri normal coordinates
        if ( ! Channel.write( (char *) actual_coordinates, sizeof(float)*3))
          return false;

        // actual tri vertices cycle
        for (int i = 0; i < 3; i++)
        {
            // take actual tri vertex coordinates
            actual_coordinates[0] = (float) tri_vertices[i]->GetX();
            actual_coordinates[1] = (float) tri_vertices[i]->GetY();
            actual_coordinates[2] = (float) tri_vertices[i]->GetZ();
            // write actual tri vertex coordinates
            if ( ! Channel.write( (char *) actual_coordinates, sizeof(float)*3))
              return false;
        }

        // write tri STL atribute
        if ( ! Channel.write( (char *) &file_tri_attribute, sizeof(unsigned short int)))
          return false;

        // take next actual tri pointer
        actual = actual->GetNext();
    }

    return true;
}

////////////////////////////////////////////////////////////
//

bool MCTriS::SaveVRML(mds::mod::CChannel& Channel)
{
    time_t              actual_time;                                            // cration time
    int                 index = 0;                                              // mesh vertices index
    MCVertex            * actual_vertex = GetVerticeS()->GetFirst();            // pointer on mesh actual vertex
    MCTri               * actual_tri = GetFirst();                              // pointer on mesh actual tri
    std::stringstream   string_buffer;


    // given channel testing
    if ( ! Channel.isConnected())
        return false;

    time(&actual_time);
    // write VRML header
    string_buffer << "#VRML V2.0 utf8" << std::endl << std::endl;
    string_buffer << "# Conversion of TRI mesh by VectEntity library." << std::endl;
    string_buffer << "# Date: " << ctime(&actual_time) << std::endl << std::endl;
    string_buffer << "Transform {" << std::endl << "children [" << std::endl;
    string_buffer << "Shape {" << std::endl;
    string_buffer << "appearance Appearance { material Material { diffuseColor 0.9882 0.9882 0.9882 } }" << std::endl;
    string_buffer << "geometry IndexedFaceSet {" << std::endl;
    string_buffer << "ccw TRUE" << std::endl << "solid TRUE" << std::endl << "creaseAngle 1.5708" << std::endl;
    // start vertex writing
    string_buffer << "coord Coordinate { point [" << std::endl;

    // cycle to write vertices into VRML file
    while(actual_vertex != NULL)
    {
        // prepare string buffer text to write vertex into VRML file
        actual_vertex->SetIndex(index);
        string_buffer << actual_vertex->GetX() << " " << actual_vertex->GetY() << " " << actual_vertex->GetZ() << "," << std::endl;
        //take next vertex
        actual_vertex = actual_vertex->GetNext();
        index++;

        // write string buffer into output stream
        if( ! Channel.write(string_buffer.str().c_str(), mds::tSize(string_buffer.str().size())) )
            return false;

        // clear string buffer
        string_buffer.str("");
    }

    // close vertex VRML part
    string_buffer << "] }" << std::endl;

    // start tri writing
    string_buffer << "coordIndex [" << std::endl;
    // cycle to write tris into VRML file
    while(actual_tri != NULL)
    {
        // prepare string buffer text to write tri into VRML file
        string_buffer << actual_tri->GetVertex(0)->GetIndex() << ", " << actual_tri->GetVertex(1)->GetIndex() << ", " << actual_tri->GetVertex(2)->GetIndex() << ", -1," << std::endl;
        // take next tri
        actual_tri = actual_tri->GetNext();

        // write string buffer into output stream
        if( ! Channel.write(string_buffer.str().c_str(), mds::tSize(string_buffer.str().size())) )
            return false;

        // clear string buffer
        string_buffer.str("");
    }

    // close tri VRML part and other sections
    string_buffer << "]" << std::endl;
    string_buffer << "}" << std::endl;
    string_buffer << "}" << std::endl;
    string_buffer << "] }" << std::endl;

    // write string buffer into output stream
    if( ! Channel.write(string_buffer.str().c_str(), mds::tSize(string_buffer.str().size())) )
        return false;

    // OK
    return true;
}

////////////////////////////////////////////////////////////
//

void MCTriS::ClearAll()
{
    // call ClearAll() from MCEntitieS
    MCEntitieS<MCTri>::ClearAll();

	// get pointer on first vertex of the container
	MCVertex	* actual_vertex = (GetVerticeS())->GetFirst();

	// cycle of all vertices of the container
	while (actual_vertex != NULL)
	{
        // remove pointer on edge from actual vertex
        actual_vertex->SetRegisteredTri(NULL);

		// take next vertex of the container
		actual_vertex = actual_vertex->GetNext();
	}
}

////////////////////////////////////////////////////////////
//

#define CSTR_SIZE(str) (sizeof(str) - 1)

MCTriS::STLToken MCTriS::getSTLToken(const char * buffer, mds::tSize &
  bufferStart, mds::tSize bufferEnd) const
{
  // skip whitespace
  while (isspace(buffer[bufferStart]) && (bufferStart < bufferEnd))
  {
    bufferStart++;
  }

  // initialize token
  STLToken token;
  token.begin = bufferStart;
  token.end = bufferStart;

  // nothing but whitespace?
  if (bufferStart >= bufferEnd)
  {
    return token;
  }

  // find end of the word
  mds::tSize word_end = bufferStart;
  while (isgraph(buffer[word_end]) && (word_end < bufferEnd))
  {
    word_end++;
  }

  // possibly number?
  if (isdigit(buffer[bufferStart]) || (buffer[bufferStart] == '-') ||
    (buffer[bufferStart] == '.'))
  {
    // can't decide correctly at the end of buffer
    if (word_end == bufferEnd)
    {
      token.type = TOKEN_UNKNOWN;
      return token;
    }

    // test for floating number
    if (this->isFloat(buffer, bufferStart, word_end))
    {
      token.type = TOKEN_NUMBER;
      token.end = bufferStart = word_end;
      return token;
    }
    else
    {
      token.type = TOKEN_ERROR;
      return token;
    }
  }

  // end tokens?
  if (!strncmp(buffer + bufferStart, "end", CSTR_SIZE("end")))
  {
    mds::tSize tmp_start = bufferStart + CSTR_SIZE("end");

    // endsolid token?
    if (((word_end - bufferStart) == CSTR_SIZE("endsolid")) && !strncmp(buffer +
      tmp_start, "solid", CSTR_SIZE("solid")))
    {
      token.type = TOKEN_ENDSOLID;
      token.end = bufferStart = word_end;
      return token;
    }

    // end facet token?
    if (((word_end - bufferStart) == CSTR_SIZE("endfacet")) && !strncmp(buffer +
      tmp_start, "facet", CSTR_SIZE("facet")))
    {
      token.type = TOKEN_ENDFACET;
      token.end = bufferStart = word_end;
      return token;
    }

    // end loop token?
    if (((word_end - bufferStart) == CSTR_SIZE("endloop")) && !strncmp(buffer +
      tmp_start, "loop", CSTR_SIZE("loop")))
    {
      token.type = TOKEN_ENDLOOP;
      token.end = bufferStart = word_end;
      return token;
    }
  }
  else
  {
    // solid token?
    if (((word_end - bufferStart) == CSTR_SIZE("solid")) && !strncmp(buffer +
      bufferStart, "solid", CSTR_SIZE("solid")))
    {
      token.type = TOKEN_SOLID;
      token.end = bufferStart = word_end;
      return token;
    }

    // facet token?
    if (((word_end - bufferStart) == CSTR_SIZE("facet")) && !strncmp(buffer +
      bufferStart, "facet", CSTR_SIZE("facet")))
    {
      token.type = TOKEN_FACET;
      token.end = bufferStart = word_end;
      return token;
    }

    // loop token?
    if (((word_end - bufferStart) == CSTR_SIZE("loop")) && !strncmp(buffer +
      bufferStart, "loop", CSTR_SIZE("loop")))
    {
      token.type = TOKEN_LOOP;
      token.end = bufferStart = word_end;
      return token;
    }

    // outer token?
    if (((word_end - bufferStart) == CSTR_SIZE("outer")) && !strncmp(buffer +
      bufferStart, "outer", CSTR_SIZE("outer")))
    {
      token.type = TOKEN_OUTER;
      token.end = bufferStart = word_end;
      return token;
    }

    // vertex token?
    if (((word_end - bufferStart) == CSTR_SIZE("vertex")) && !strncmp(buffer +
      bufferStart, "vertex", CSTR_SIZE("vertex")))
    {
      token.type = TOKEN_VERTEX;
      token.end = bufferStart = word_end;
      return token;
    }

    // normal token?
    if (((word_end - bufferStart) == CSTR_SIZE("normal")) && !strncmp(buffer +
      bufferStart, "normal", CSTR_SIZE("normal")))
    {
      token.type = TOKEN_NORMAL;
      token.end = bufferStart = word_end;
      return token;
    }
  }

  // test if we are able to detect a keyword at the end of buffer - replace
  // "endsolid" with the longest allowed keyword
  if ((word_end == bufferEnd) && ((word_end - bufferStart) <
    CSTR_SIZE("endsolid")))
  {
    // too short to decide
    token.type = TOKEN_UNKNOWN;
    return token;
  }
  else
  {
    // probably some identifier
    token.type = TOKEN_IDENTIFIER;
    token.end = bufferStart = word_end;
    return token;
  }
}

////////////////////////////////////////////////////////////
//

bool MCTriS::isFloat(const char * buffer, const mds::tSize wordStart,
  const mds::tSize wordEnd) const
{
  mds::tSize index = wordStart;

  // negative?
  if (buffer[index] == '-') index++;

  // integer part
  while (isdigit(buffer[index])) index++;

  // decimal part?
  if (buffer[index] == '.')
  {
    index++;
    while (isdigit(buffer[index])) index++;
  }

  // exponent?
  if ((buffer[index] == 'e') || (buffer[index] == 'E'))
  {
    index++;

    // negative exponent?
    if (buffer[index] == '-') index++;

    // exponent
    while (isdigit(buffer[index])) index++;
  }

  // if at end of the word it's floating number
  return index == wordEnd;
}

////////////////////////////////////////////////////////////
//

 void MCTriS::FlipTrisNormal()
 {
	// get pointer on first tri of the container
	MCTri   * actual_tri = GetFirst();


	// cycle of all tris in the container
	while (actual_tri != NULL)
	{
        // flip normal of actual tri
        actual_tri->InverseOrientation();

		// take next tri of the container
		actual_tri = actual_tri->GetNext();
	}
 }

////////////////////////////////////////////////////////////
//

// void MCTriS::
// {
// }

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

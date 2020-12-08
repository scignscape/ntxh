//==============================================================================
/*! \file
 * Medical Data Segmentation Toolkit (MDSTk)    \n
 * Copyright (c) 2004-2009 by PGMed@FIT         \n
 *
 * Author:  Radek Barton, ibarton@fit.vutbr.cz  \n
 * Date:    2008/12/03                          \n
 *
 * $Id: mdsPredictor.h 1863 2010-08-31 20:40:15Z spanel $
 *
 * Description:
 * - Various compression predictor channels.
 */

#ifndef MDS_PREDICTOR_H
#define MDS_PREDICTOR_H

#include <MDSTk/Base/mdsData.h>
//#include <MDSTk/Base/mdsGlobalLog.h>
#include <MDSTk/Image/mdsPixelTypes.h>

#include "mdsChannel.h"


namespace mds
{
namespace mod
{

//==============================================================================
/*!
 * Class providing base for compression predictor channels.
 */
class MDS_MODULE_EXPORT CPredictorChannel : public CChannel
{
public:
    //! Smart pointer type.
    MDS_SHAREDPTR(CPredictorChannel);

public:
    //! Default constructor.
    CPredictorChannel(CChannel *pChannel = NULL) : m_spChannel(pChannel)
    {
        if( pChannel )
        {
            m_Type = CH_PREDICTOR | pChannel->getType();
            m_Medium = pChannel->getMedium();
        }
    }

    //! Virtual destructor.
    virtual ~CPredictorChannel() {}

    //! Returns pointer to the underlying channel.
    CChannel *getChannel() { return m_spChannel.get(); }

    //! Sets the underlying channel.
    virtual void setChannel(CChannel *pChannel)
    {
        m_spChannel = pChannel;
        if( pChannel )
        {
            m_Type = CH_PREDICTOR | pChannel->getType();
            m_Medium = pChannel->getMedium();
        }
    }


    //! Connects to the opposite channel side.
    //! - Returns false on failure and/or timeout elapsed.
    virtual bool connect(unsigned uTimeout = CH_CONNECTION_TIMEOUT)
    {
        return (m_spChannel.get() && m_spChannel->connect(uTimeout));
    }

    //! Listens for the opposite channel side.
    //! - Returns false on failure and/or timeout elapsed.
    virtual bool listen(unsigned uTimeout = CH_CONNECTION_TIMEOUT)
    {
        return (m_spChannel.get() && m_spChannel->listen(uTimeout));
    }

    //! Disconnects from the opossite channel side.
    virtual void disconnect() { m_spChannel->disconnect(); }

    //! Method for testing channel errors such as:
    //! - Disconnected or broken channel.
    //! - Reading after end of input.
    virtual bool isConnected() { return (m_spChannel.get() && m_spChannel->isConnected()); }


    //! Waits for data.
    //! - Returns false if a timeout elapses and/or the channel is not input.
    virtual bool wait(unsigned uTimeout = CH_WAIT_TIMEOUT)
    {
        return m_spChannel->wait(uTimeout);
    }

    //! Reads difference data from underlying channel and decomputes them.
    //! - In case of error or reading after end of input
    //!   the number of successfully readed bytes is returned.
    virtual int read(char *pcData, int iLength) = 0;

    //! Computes data differences and writes them to underlying channel.
    virtual bool write(const char *pcData, int iLength) = 0;

    //! Finalizes all writing operations (flushes internal buffers, etc.).
    virtual bool flush()
    {
        return (m_spChannel.get() && m_spChannel->flush());
    }

protected:
    //! Underlying channel.
    CChannelPtr m_spChannel;
};

//==============================================================================
/*!
 * Smart pointer to compression predictor channel.
 */
typedef CPredictorChannel::tSmartPtr CPredictorChannelPtr;


//==============================================================================
/*!
 * Class providing a simple transposition of lower and higher bytes.
 * Such transposition may increase compress rate of a simple 8-bit RLE.
 * - low high low high low high -> low low low high high high
 * - It is expected that a sequence of values of type T will be written.
 */
template <typename T>
class CByteTranspose : public CPredictorChannel
{
public:
    //! Smart pointer type.
    MDS_SHAREDPTR(CByteTranspose);

    //! Input value.
    typedef T tValue;

public:
    //! Default constructor.
    CByteTranspose(CChannel *pChannel = NULL) : CPredictorChannel(pChannel) {}

    //! Virtual destructor.
    virtual ~CByteTranspose() { this->flush(); }

    //! Reads data from underlying channel and transposes them.
    virtual int read(char * data, int length);

    //! Transposes data and writes them to underlying channel.
    virtual bool write(const char * data, int length);

protected:
    //! Internal buffer.
    mds::base::CData<char> m_Buffer;
};


//==============================================================================
/*!
 * Class providing a simple difference predictor of density data.
 * - Lower and higher bytes are reordered into two continuous blocks.
 */
class MDS_MODULE_EXPORT CDensityPredictor : public CPredictorChannel
{
public:
    //! Smart pointer type.
    MDS_SHAREDPTR(CDensityPredictor);

    //! Input value.
    typedef mds::img::tDensityPixel tValue;

public:
    //! Default constructor.
    CDensityPredictor(CChannel * pChannel = NULL) : CPredictorChannel(pChannel) {}

    //! Virtual destructor.
    virtual ~CDensityPredictor() { this->flush(); }

    //! Reads difference data from underlying channel and decomputes them.
    virtual int read(char * data, int length);

    //! Computes data differences and writes them to underlying channel.
    virtual bool write(const char * data, int length);

protected:
    //! Internal buffer.
    mds::base::CData<unsigned char> m_Buffer;
};


//==============================================================================
/*
 * Implementation...
 */
#include "mdsPredictor.hxx"


} // namespace mod
} // namespace mds

#endif // MDS_PREDICTOR_H

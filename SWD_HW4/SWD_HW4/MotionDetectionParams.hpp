/// No Cpoyright file
/// Robert BOSCH GMBH @2020
/// SoftwareDesigner Training - Homework solution
/// --------------------------------------------------------
/// Author: @Richard Csaba Hafenscher
/// Author: @Istvan Golarits
/// --------------------------------------------------------
/// Purpose of file: 
/// --------------------------------------------------------

#ifndef MOTION_DETECTION_PARAM_HPP
#define MOTION_DETECTION_PARAM_HPP

#include <stdlib.h>
#include <string>
#include <vector>

namespace istvan_richard
{
    class CMotionDetectionParam
    {
    public:

        CMotionDetectionParam() :
            
        {}

        const int  fGetStartOfMonitoring() const;
        const int  fGetOutOfNormalTimeWarningThreshold() const;
        const int fGetNormalTimeWarningThreshold() const;
        const int fGetNoResponseTimeThreshold() const;
        const int fGetNumberOfRetry() const;
        const DateTime fGetStartOfMonitoring() const;
        const DateTime fGetEndOfMonitoring() const;

    private:
        DateTime m_StartOfMonitoring_dt;
        DateTime m_EndOfMonitoring_dt;
        int m_SamplingRate_i32;
        int m_OutOfNormalTimeWarningThreshold_i32;
        int m_NormalTimeWarningThreshold_i32;
        int m_NoResponseTimeThreshold_i32;
        int m_NumberOfRetry_i32;

    };


}//end of namespace

#endif#pragma once

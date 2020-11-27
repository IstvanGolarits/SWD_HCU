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
#include "CustomTypes.hpp"

namespace istvan_richard
{
    class CMotionDetectionParam
    {
    public:

        CMotionDetectionParam() :
            m_StartOfMonitoring_dt               (DailyDateTime(std::string(" "), 7, 0, 0)),
            m_EndOfMonitoring_dt                 (DailyDateTime(std::string(" "), 21, 0, 0)),
            m_SamplingRate_i32                   (1),
            m_OutOfNormalTimeWarningThreshold_i32(10),
            m_NormalTimeWarningThreshold_i32    (10),
            m_NoResponseTimeThreshold_i32       (10),
            m_NumberOfRetry_i32                 (2)
        {}

        CMotionDetectionParam(const CMotionDetectionParam& f__r) :
            m_StartOfMonitoring_dt(DailyDateTime(std::string(" "), 7, 0, 0)),
            m_EndOfMonitoring_dt(DailyDateTime(std::string(" "), 21, 0, 0)),
            m_SamplingRate_i32(1),
            m_OutOfNormalTimeWarningThreshold_i32(10),
            m_NormalTimeWarningThreshold_i32(10),
            m_NoResponseTimeThreshold_i32(10),
            m_NumberOfRetry_i32(2)
        {
            if (this != &f__r)
            {
                this->m_StartOfMonitoring_dt = f__r.m_StartOfMonitoring_dt;
                this->m_EndOfMonitoring_dt = f__r.m_EndOfMonitoring_dt;
                this->m_SamplingRate_i32 = f__r.m_SamplingRate_i32;
                this->m_OutOfNormalTimeWarningThreshold_i32 = f__r.m_OutOfNormalTimeWarningThreshold_i32;
                this->m_NormalTimeWarningThreshold_i32 = f__r.m_NormalTimeWarningThreshold_i32;
                this->m_NoResponseTimeThreshold_i32 = f__r.m_NoResponseTimeThreshold_i32;
                this->m_NumberOfRetry_i32 = f__r.m_NumberOfRetry_i32;
            }
        }

        CMotionDetectionParam(const DateTime& f_begTime_r, const DateTime& f_endTime_r, const int& f_SampRate_r,
        const int& f_OutOfNormThresh_r, const int& f_NormThresh_r, const int& NoRespTimeThresh_r,
            const int& f_NumOfTry_r):
            m_StartOfMonitoring_dt(f_begTime_r),
            m_EndOfMonitoring_dt(f_endTime_r),
            m_SamplingRate_i32(f_SampRate_r),
            m_OutOfNormalTimeWarningThreshold_i32(f_OutOfNormThresh_r),
            m_NormalTimeWarningThreshold_i32(f_NormThresh_r),
            m_NoResponseTimeThreshold_i32(NoRespTimeThresh_r),
            m_NumberOfRetry_i32(f_NumOfTry_r)
        {}


        const int  fGetSamplingRate() const
        {
            return m_SamplingRate_i32;
        }
        const int  fGetOutOfNormalTimeWarningThreshold() const
        {
            return m_OutOfNormalTimeWarningThreshold_i32;
        }
        const int fGetNormalTimeWarningThreshold() const
        {
            return m_NormalTimeWarningThreshold_i32;
        }
        const int fGetNoResponseTimeThreshold() const
        {
            return m_NoResponseTimeThreshold_i32;
        }
        const int fGetNumberOfRetry() const
        {
            return m_NumberOfRetry_i32;
        }
        DateTime fGetStartOfMonitoring()
        {
            return m_StartOfMonitoring_dt;
        }
        DateTime fGetEndOfMonitoring()
        {
            return m_EndOfMonitoring_dt;
        }

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

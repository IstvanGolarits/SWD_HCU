/// No Cpoyright file
/// Robert BOSCH GMBH @2020
/// SoftwareDesigner Training - Homework solution
/// --------------------------------------------------------
/// Author: @Richard Csaba Hafenscher
/// Author: @Istvan Golarits
/// --------------------------------------------------------
/// Purpose of file: 
/// --------------------------------------------------------
#ifndef GENERIC_INTERFACE_FOR_MOTION_SENSOR
#define GENERIC_INTERFACE_FOR_MOTION_SENSOR

#include "CustomTypes.hpp"
#include <string>

namespace istvan_richrad
{
    class CGenericMotionSensorInterface
    {
    private:
        std::string sSensorType;        
        float sensorRange_float32;
        float samplingRate_float32;        
        std::string GenericSensorInfo;


    public:
        CGenericMotionSensorInterface();

        CGenericMotionSensorInterface
        (
            IN std::string sSensorType,           
            IN float sensorRange_float32,
            IN float samplingRate_float32,            
            IN std::string GenericSensorInfo
        );

        std::string sGetSensorType()const;        
        float fGetSensorRange()const;
        float fGetSamplingRate()const;
        std::string sGetGenericSensorInfo()const;




    };
}


#endif // !GENERIC_INTERFACE_FOR_MOTION_SENSOR



/// No Cpoyright file
/// Robert BOSCH GMBH @2020
/// SoftwareDesigner Training - Homework solution
/// --------------------------------------------------------
/// Author: @Richard Csaba Hafenscher
/// Author: @Istvan Golarits
/// --------------------------------------------------------
/// Purpose of file: 
/// --------------------------------------------------------
#ifndef GENERIC_INTERFACE_FOR_CAMERA
#define GENERIC_INTERFACE_FOR_CAMERA

#define DEFAULT_CAMERA_RESOLUTION 0
#define DEFAULT_CAMERA_RANGE 0.0f
#define DEFAULT_CAMERA_SAMPLING_RATE 0.0f
#define DEAFULT_CAMERA_FPS 0

#include "CustomTypes.hpp"
#include <string>

namespace istvan_richrad
{
 

    class CGenericCameraInterface
    {
    private: 
        std::string sSensorType;
        int resolutionHeight_int64;
        int resolutionWidth_int64;
        float range_float32;
        float samplingRate_float32;
        int fps_int64;
        std::string GenericCameraInfo;


    public:       
        CGenericCameraInterface();

        CGenericCameraInterface
        (
            IN std::string sSensorType,
            IN int resolutionHeight_int64,
            IN int resolutionWidth_int64,
            IN float range_float32,
            IN float samplingRate_float32,
            IN int fps_int64,
            IN std::string GenericCameraInfo
        );

        const std::string sGetSensorType()const;
        const int iGetResolutionHeight()const;
        const int iGetResolutionWidth()const;
        const int iGetFPS()const;
        const float fGetCameraRange()const;
        const float fGetSamplingRate()const;
        const std::string sGetGenericCameraInfo()const;




    };

}// end of namespace
#endif // !GENERIC_INTERFACE_FOR_CAMERA
#include "GenericInterfaceForCamera.hpp"

namespace istvan_richrad
{
	CGenericCameraInterface::CGenericCameraInterface()
	{
		sSensorType = "";
		resolutionHeight_int64= DEFAULT_CAMERA_RESOLUTION;
		resolutionWidth_int64= DEFAULT_CAMERA_RESOLUTION;
		range_float32= DEFAULT_CAMERA_RANGE;
		samplingRate_float32= DEFAULT_CAMERA_SAMPLING_RATE;
		fps_int64= DEAFULT_CAMERA_FPS;
		GenericCameraInfo="";

	}

	CGenericCameraInterface::CGenericCameraInterface(IN std::string sSensorType, IN  int resolutionHeight_int64, IN int resolutionWidth_int64, IN float range_float32, IN float samplingRate_float32, IN  int fps_int64, IN std::string GenericCameraInfo)
	{
		this->sSensorType = sSensorType;
		this->resolutionHeight_int64 = resolutionHeight_int64;
		this->resolutionWidth_int64 = resolutionWidth_int64;
		this->range_float32 = range_float32;
		this->samplingRate_float32 = samplingRate_float32;
		this->fps_int64 = fps_int64;
		this->GenericCameraInfo = GenericCameraInfo;

	}
	
	const std::string CGenericCameraInterface::sGetSensorType()const
	{
		return sSensorType;
	};
	const int CGenericCameraInterface::iGetResolutionHeight()const
	{
		return resolutionHeight_int64;
	}
	const int CGenericCameraInterface::iGetResolutionWidth()const
	{
		return resolutionWidth_int64;
	}
	const int CGenericCameraInterface::iGetFPS()const
	{
		return fps_int64;
	}
	const float CGenericCameraInterface::fGetCameraRange()const
	{
		return range_float32;
	}
	const float CGenericCameraInterface::fGetSamplingRate()const
	{
		return samplingRate_float32;
	}
	const std::string CGenericCameraInterface::sGetGenericCameraInfo()const
	{
		return GenericCameraInfo;
	}
}

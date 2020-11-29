#include "GenericInterfaceForMotionSensor.hpp"

namespace istvan_richrad
{
	CGenericMotionSensorInterface::CGenericMotionSensorInterface()
	{
		sSensorType = "";	
		samplingRate_float32 = 0.0;				
		sensorRange_float32 =0.0;		
		GenericSensorInfo = "";		

	}

	CGenericMotionSensorInterface::CGenericMotionSensorInterface(IN std::string sSensorType,IN float sensorRange_float32,IN float samplingRate_float32,IN std::string GenericSensorInfo)
	{
		this->sSensorType = sSensorType;
		this->sensorRange_float32 = sensorRange_float32;
		this->samplingRate_float32 = samplingRate_float32;
		this->GenericSensorInfo = GenericSensorInfo;
		

	}

	std::string CGenericMotionSensorInterface::sGetSensorType()const
	{
		return sSensorType;
	};	
	float CGenericMotionSensorInterface::fGetSensorRange()const
	{
		return sensorRange_float32;
	}
	float CGenericMotionSensorInterface::fGetSamplingRate()const
	{
		return samplingRate_float32;
	}
	std::string CGenericMotionSensorInterface::sGetGenericSensorInfo()const
	{
		return GenericSensorInfo;
	}
}

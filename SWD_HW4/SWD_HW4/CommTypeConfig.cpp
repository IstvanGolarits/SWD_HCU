#include "CustomTypes.hpp"
#include "CommTypeConfig.hpp"


namespace istvan_richrad
{
	CCommTypeConfig::CCommTypeConfig()
	{
		this->CommunicationType = eCommunicationType::ComTypeBlueTooth;
	}

	CCommTypeConfig::CCommTypeConfig(IN eCommunicationType eSelectedCommType)
	{
		this->CommunicationType = eSelectedCommType;
	}
	const eCommunicationType CCommTypeConfig::eGetCommunicationType() const
	{
		return this->CommunicationType;
	}



}






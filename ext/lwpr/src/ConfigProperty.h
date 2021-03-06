/*
 * $Id: ConfigProperty.h 1 2012-01-17 02:31:57Z  $
 */
#ifndef LWPR_CONFIG_PROPERTY_H__
#define LWPR_CONFIG_PROPERTY_H__
#include "LWPRType.h"
#include "Exception.h"
#include <map>
#include <string>

namespace LWPR
{
	typedef std::map< std::string, std::string > OptionProperty;

	/**
	 * 参数优先级： 代码 < 环境变量 < 配置文件 < 命令行参数
	 */
	class ConfigProperty
	{
	public:
		ConfigProperty();
		virtual ~ConfigProperty();

		void ConfigInit(int argc, char* argv[]);

		void ConfigInit();

		void SetProperty(const OptionProperty& prop);

		virtual void DoPropConstruct() = 0;

		virtual std::string GetPreConfigFile();

		static std::string GetPropertyLabel(const char* name);

		std::vector<std::string>& GetOtherArgs();

		std::string GetProgramName();

	protected:
		int GetPropertyValue(const char* name, int default_value);
		bool GetPropertyValue(const char* name, bool default_value);
		std::string GetPropertyValue(const char* name, const std::string& default_value);
		std::string GetPropertyValue(const char* name, const char* default_value);

	protected:
		OptionProperty				m_OptionProperty;
		std::vector<std::string>	m_vtOtherArgs;		// 含程序名，argv[0]
	};

	DEFINE_EXCEPTION(LWPR_FILE_NOT_EXIST);
};

#endif // end of LWPR_CONFIG_PROPERTY_H__

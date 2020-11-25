//
// Created by Avinal on 23-11-2020.
//

#ifndef BASICPP_VARIABLES_HPP
#define BASICPP_VARIABLES_HPP

#include "basicpp_config.hpp"

#include <string_view>
#include <variant>
#include <string>
#include <vector>
#include <unordered_map>
#include <any>

namespace basicpp
{
	typedef enum
	{
		variable_type_unknown,
		variable_type_numeric,
		variable_type_string
	} variable_type;

	typedef std::variant<float, std::string> variable_value;

	class BASICPP_API variables
	{
	private:
		std::string_view name;
		variable_type type;
		variable_value value;
		bool is_array;
		size_t nr_dimensions;
		size_t dimensions[5];
		std::vector<char> array;
		std::unordered_map<std::string_view, std::any> dictionary;

	public:
		variables();

		variables(std::string_view& name, variable_type& type, size_t& nr_dimensions, size_t dimensions[]);

		variables get(std::string_view name);

		std::string_view get_string(std::string_view name);

		float get_numeric(std::string_view name);

		variable_type get_type(std::string_view name);

		void set_string(std::string_view name, std::string_view value);

		void set_numeric(std::string_view name, float value);

		~variables();

	};

}
#endif //BASICPP_VARIABLES_HPP

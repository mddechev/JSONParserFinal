#include "../../includes/json_types/JSONNumber.hpp"
#include <cstdio>

JSONNumber::JSONNumber(double value)
    :value(value) {}

String JSONNumber::toString() const {
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%g", value);
    return String(buffer);
}

JSONValue* JSONNumber::clone() const {
    return new JSONNumber(*this);
}

void JSONNumber::print(std::ostream &outputStream, size_t indent) const {
    outputStream << value;
}

bool JSONNumber::contains(const String &value) const {
    // return this->toString().Contains(value);
    try {
        double inputValue = std::stod(value.C_str());
        return this->value == inputValue;
    } catch (...) {
        return false;
    }
}


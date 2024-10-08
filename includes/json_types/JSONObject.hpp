#ifndef _JSON_OBJECT_HPP_
#define _JSON_OBJECT_HPP_

#include "../json_types/JSONKeyPair.hpp"

class JSONObject: public JSONValue {
public:
    JSONObject() = default;
    JSONObject(const JSONObject& other);
    JSONObject(JSONObject&& other) noexcept;
    ~JSONObject() noexcept override;

    JSONObject& operator=(const JSONObject& other);
    JSONObject& operator=(JSONObject&& other) noexcept;

    String toString() const override;

    JSONValue * clone() const override;

    void print(std::ostream &outputStream = std::cout, size_t indent = 0) const override;
    
    void search(const String &key, Vector<JSONValue*>& searchResultsArray) const override;

    void set(const Vector<String> &path, JSONValue *const value) override;

    void create(const Vector<String> &path, JSONValue *const value) override;

    void remove(const Vector<String> &path) override;

    bool contains(const String &value) const override;

public:
    void addPair(const String& key, JSONValue* value);    
    void removePair(const String& key);

private:
    JSONKeyPair* getPair(const String& key);
    size_t getValueIndex(const String& key) const;
    void copyFrom(const JSONObject& other);
    void moveFrom(JSONObject&& other) noexcept;
    void free();

private:
    Vector<JSONKeyPair*> values;
};

#endif //_JSON_OBJECT_HPP_
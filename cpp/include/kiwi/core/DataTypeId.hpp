
#pragma once
#ifndef KIWI_CORE_DATATYPEID_HPP
#define KIWI_CORE_DATATYPEID_HPP

#include "kiwi/core/Commons.hpp"
#include "kiwi/core/TypeIndex.hpp"

namespace kiwi{
namespace core{

class DataTypeInfo;

class DataTypeId
{
public:
    typedef size_t TypeIndex;
    enum{ INVALID, STATIC, RUNTIME };

    static const DataTypeId Null;

    DataTypeId()
    :_id(0), _category(INVALID)
    {
    }
    
    DataTypeId( TypeIndex intId, uint8 category )
    :_id(intId), _category(category)
    {
    }

    DataTypeId( const DataTypeId& toCopy )
    :_id(toCopy._id), _category(toCopy._category)
    {
    }

    template<typename T>
    static DataTypeId TypeOf()
    {
        return DataTypeId( TypeIndexGenerator<T>::Get(), STATIC );
    }

    static DataTypeId NullType()
    {
        return DataTypeId();
    }
    
    bool operator==(const DataTypeId& other) const
    {
        return ((other._id == _id) && (other._category == _category));
    }

    bool operator!=(const DataTypeId& other) const
    {
        return ((other._id != _id) || (other._category != _category));
    }

    bool isRuntimeType() const
    {
        return _category == RUNTIME;
    }
    
    bool isStaticType() const
    {
        return _category == STATIC;
    }

    const DataTypeInfo * dataTypeInfo() const;
    
private:
    TypeIndex  _id;
    uint8   _category; 
};


}//namespace
}//namespace

#endif
#pragma once

#ifndef KIWI_TEXT_LINE_HPP
#define KIWI_TEXT_LINE_HPP

namespace kiwi{
namespace text{


	
class Line
{
public:
	virtual kiwi::int8_t operator[]( kiwi::int32_t pos ) const = 0;
	virtual kiwi::int8_t& operator[]( kiwi::int32_t pos ) = 0;
	virtual uint32_t size() const = 0;
	virtual kiwi::string str() const = 0;
	virtual void operator+=( char const* txt ) = 0;
	virtual void operator+=( kiwi::string txt ) = 0;
	virtual ~Line(){}

	bool operator==( const kiwi::text::Line& toComp)
	{
		if( size() != toComp.size() ) return false;
		for(int i = 0; i < size(); ++i)
		{
			if( (*this)[i] != toComp[i] ) return false;
		}
		return true;
	}

};


}//namespace
}//namespace

#endif

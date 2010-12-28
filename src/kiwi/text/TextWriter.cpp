// Copyright (c) 2010 Nicolas Silva
// All rights reserved.
//      Redistribution and use in source and binary forms, with or without
//      modification, are permitted provided that the following conditions are
//      met:
//      
//      * Redistributions of source code must retain the above copyright
//        notice, this list of conditions and the following disclaimer.
//      * Redistributions in binary form must reproduce the above
//        copyright notice, this list of conditions and the following disclaimer
//        in the documentation and/or other materials provided with the
//        distribution.
//      * Neither the name of the  nor the names of its
//        contributors may be used to endorse or promote products derived from
//        this software without specific prior written permission.
//      
//      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
//      "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
//      LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
//      A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
//      OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
//      SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
//      LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//      DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//      THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
//      (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
//      OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


#include "TextWriter.hpp"
#include "kiwi/utils/modulo.hpp"

namespace kiwi{
namespace text{




TextWriter::TextWriter( AbstractTextContainer& container 
	, portIndex_t index )
{
	init(container, index);
}

TextWriter::TextWriter( core::Node::WriterInputPort& port )
{
	AbstractTextContainer* tc = dynamic_cast<AbstractTextContainer*>(
		port.connectedOutput()->subPort()->node() );
	
	if( tc ) init( *tc, port.connectedOutput()->subPort()->index() );
	else
	{
		Debug::error() 
			<< "TextWriter::constructor error:"
			<<" Unable to determine the Container type."
			<< endl();
	}
}

TextWriter::TextWriter( core::Node::WriterOutputPort& port )
{
	AbstractTextContainer* tc = dynamic_cast<AbstractTextContainer*>(
		port.subPort()->node() );
	
	if( tc ) init( *tc, port.subPort()->index() );
	else
	{
		Debug::error() 
			<< "TextWriter::constructor error:"
			<<" Unable to determine the Container type."
			<< endl();
	}
}

void TextWriter::init( AbstractTextContainer& container
	, portIndex_t portIndex )
{
	_container = &container;
}

kiwi::uint32_t TextWriter::nbLines() const
{
	return _container->nbLines();
}

kiwi::uint32_t TextWriter::nbChars() const
{
	
}


void TextWriter::reset() 
{
	_container->clear();
}
	
	
}// namespace	
}// namespace	

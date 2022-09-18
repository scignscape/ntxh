/*
Copyright (c) 2008-2013, Northwestern University
All rights reserved.
 
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
 
  Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.
 
  Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.
 
  Neither the name of the Northwestern University nor the names of its contributors
  may be used to endorse or promote products derived from this software
  without specific prior written permission.
 
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CCD_CE_None
#define _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CCD_CE_None



namespace AIMXML
{

namespace iso
{	

class CCD_CE_None : public TypeBase
{
public:
	AIMXML_EXPORT CCD_CE_None(xercesc::DOMNode* const& init);
	AIMXML_EXPORT CCD_CE_None(CCD_CE_None const& init);
	void operator=(CCD_CE_None const& other) { m_node = other.m_node; }
	static altova::meta::ComplexType StaticInfo() { return altova::meta::ComplexType(types + _altova_ti_iso_altova_CCD_CE_None); }

	MemberAttribute<string_type,_altova_mi_iso_altova_CCD_CE_None_altova_validTimeLow, 0, 0> validTimeLow;	// validTimeLow Cstring

	MemberAttribute<string_type,_altova_mi_iso_altova_CCD_CE_None_altova_validTimeHigh, 0, 0> validTimeHigh;	// validTimeHigh Cstring

	MemberAttribute<string_type,_altova_mi_iso_altova_CCD_CE_None_altova_controlActRoot, 0, 0> controlActRoot;	// controlActRoot CUid

	MemberAttribute<string_type,_altova_mi_iso_altova_CCD_CE_None_altova_controlActExtension, 0, 0> controlActExtension;	// controlActExtension Cstring
	MemberAttribute<string_type,_altova_mi_iso_altova_CCD_CE_None_altova_nullFlavor, 0, 15> nullFlavor;	// nullFlavor CNullFlavor

	MemberAttribute<string_type,_altova_mi_iso_altova_CCD_CE_None_altova_flavorId, 0, 0> flavorId;	// flavorId Cstring
	MemberAttribute<string_type,_altova_mi_iso_altova_CCD_CE_None_altova_updateMode, 0, 8> updateMode;	// updateMode CUpdateMode

	MemberAttribute<string_type,_altova_mi_iso_altova_CCD_CE_None_altova_code, 0, 0> code;	// code Cstring

	MemberAttribute<string_type,_altova_mi_iso_altova_CCD_CE_None_altova_codeSystem, 0, 0> codeSystem;	// codeSystem CUid

	MemberAttribute<string_type,_altova_mi_iso_altova_CCD_CE_None_altova_codeSystemName, 0, 0> codeSystemName;	// codeSystemName Cstring

	MemberAttribute<string_type,_altova_mi_iso_altova_CCD_CE_None_altova_codeSystemVersion, 0, 0> codeSystemVersion;	// codeSystemVersion Cstring

	MemberAttribute<string_type,_altova_mi_iso_altova_CCD_CE_None_altova_valueSet, 0, 0> valueSet;	// valueSet Cstring

	MemberAttribute<string_type,_altova_mi_iso_altova_CCD_CE_None_altova_valueSetVersion, 0, 0> valueSetVersion;	// valueSetVersion Cstring

	MemberAttribute<string_type,_altova_mi_iso_altova_CCD_CE_None_altova_id, 0, 0> id;	// id CID
	MemberAttribute<string_type,_altova_mi_iso_altova_CCD_CE_None_altova_codingRationale, 1, 4> codingRationale;	// codingRationale Cset_CodingRationale
	MemberElement<iso::CST, _altova_mi_iso_altova_CCD_CE_None_altova_displayName> displayName;
	struct displayName { typedef Iterator<iso::CST> iterator; };
	MemberElement<iso::CED_Text, _altova_mi_iso_altova_CCD_CE_None_altova_originalText> originalText;
	struct originalText { typedef Iterator<iso::CED_Text> iterator; };
	MemberElement<iso::CCR, _altova_mi_iso_altova_CCD_CE_None_altova_qualifier> qualifier;
	struct qualifier { typedef Iterator<iso::CCR> iterator; };
	MemberElement<iso::CCDGroup, _altova_mi_iso_altova_CCD_CE_None_altova_group> group;
	struct group { typedef Iterator<iso::CCDGroup> iterator; };
	MemberElement<iso::CCD_CE, _altova_mi_iso_altova_CCD_CE_None_altova_translation> translation;
	struct translation { typedef Iterator<iso::CCD_CE> iterator; };
	MemberElement<iso::CXReference, _altova_mi_iso_altova_CCD_CE_None_altova_source> source;
	struct source { typedef Iterator<iso::CXReference> iterator; };
	AIMXML_EXPORT void SetXsiType();
};



} // namespace iso

}	// namespace AIMXML

#endif // _ALTOVA_INCLUDED_AIMXML_ALTOVA_iso_ALTOVA_CCD_CE_None

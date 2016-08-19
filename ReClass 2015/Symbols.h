#pragma once

#include "SymbolReader.h"
#include <map>

class Symbols
{
public:
	Symbols();
	~Symbols();

	void Cleanup();
	bool Init();
	bool IsInitialized() { return m_bInitialized; }

	bool LoadSymbolsForModule(CString szModulePath, size_t dwBaseAddr, DWORD dwSizeOfImage);

	SymbolReader* GetSymbolsForModule(CString module);

private:
	//typedef std::pair<CString, size_t> key_type;
	std::map<CString, SymbolReader*> symbols;

	bool m_bInitialized;

	CString m_strSearchPath;
};

extern Symbols sym;
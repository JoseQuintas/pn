/**
 * @file OptionsIni.h
 * @brief Ini configuration functionality.
 * @author Simon Steele
 * @note Copyright (c) 2004 Simon Steele <s.steele@pnotepad.org>
 *
 * Programmers Notepad 2 : The license file (license.[txt|html]) describes 
 * the conditions under which this source may be modified / distributed.
 */

#ifndef inioptions_h__included
#define inioptions_h__included

class KeyMap;

class IniOptions : public Options
{
	friend class OptionsFactory;

public:
	virtual ~IniOptions();

	virtual void Set(LPCTSTR subkey, LPCTSTR value, bool bVal);
	virtual void Set(LPCTSTR subkey, LPCTSTR value, int iVal);
	virtual void Set(LPCTSTR subkey, LPCTSTR value, LPCTSTR szVal);

	virtual bool Get(LPCTSTR subkey, LPCTSTR value, bool bDefault);
	virtual int Get(LPCTSTR subkey, LPCTSTR value, int iDefault);
	virtual tstring Get(LPCTSTR subkey, LPCTSTR value, LPCTSTR szDefault);

protected:
	IniOptions();

	virtual void group(LPCTSTR location);
	virtual void ungroup();

	bool groupLocked;
	KeyMap* keyMap;
	TCHAR*	_filename;
	LPCTSTR _group;
};

#endif
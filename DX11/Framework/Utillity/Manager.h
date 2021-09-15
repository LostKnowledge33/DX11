#pragma once

class CManager : public CSingleton<CManager> {
private:
	friend class CSingleton;

	static CManager* instance;

	CManager();
	~CManager();

public:

};
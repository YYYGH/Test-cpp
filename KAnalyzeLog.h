#ifndef _ANALYZE_LOG_H_
#define _ANALYZE_LOG_H_

#include <vector>
#include <fstream> 
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <clocale>
#include <algorithm>
using namespace std;

#ifdef _WIN32
#include <ctime> //win32�µ�ͷ�ļ�
#include <windows.h>
#include<winnls.h>
#endif

#ifdef linux
#include <sys/time.h>  //Linux�µ�ͷ�ļ�
#include <unistd.h>
#endif


using namespace std;


struct LocalTime;
class KAnalyzeLog;
struct LogInformation;
struct LocalTime
{
	int				year;
	int				month;
	int				day;
	int				hour;
	int				minute;
	int				second;
};
class KAnalyzeLog
{
public:
	KAnalyzeLog();
	~KAnalyzeLog();

	void						OutPut(KAnalyzeLog *pAnalyze, int iIndex);//������
	int							InPut();//��������
	int							InsertNewType(char* type);//����������
	int							Search();//Ӳ�̲����ַ���
	char*						GetInPutTypeFirst(char *destiation);//��һ�λ�ȡ�����ַ�������
	char*						GetInPutTypeLast(KAnalyzeLog *pAnalyze, char* Source, char *destiation);//���һ�λ�ȡ����
	void						StringToInt(KAnalyzeLog *pAnalyze, char* Source);//��ʱ���ַ���ת��������
	//��� 
	char*						DeleteFirstEmpty(KAnalyzeLog *pAnalyze, char* Source);//����ַ�����λ���ַ��ǿո���ȥ���ո�
	char*						DeleteLastEmpty(KAnalyzeLog *pAnalyze, char* Source);
	wchar_t*					DeleteWLastEmpty(KAnalyzeLog *pAnalyze, wchar_t* Source);
	wchar_t*					DeleteWFirstEmpty(KAnalyzeLog *pAnalyze, wchar_t *Source);
	char*						GetProcessId(KAnalyzeLog *pAnalyze);//#����
	char*						GetLocalTime(KAnalyzeLog *pAnalyze);//��ȡ����ʱ��
	char*						LocalTimetoUTC(KAnalyzeLog *pAnalyze);//����ʱ��תUTCʱ��
	char*						GetLogType(KAnalyzeLog *pAnalyze, int iIndex);//��־����
	char*						GetLogName(KAnalyzeLog *pAnalyze, int iIndex);//���� 
	char*						GetTime(KAnalyzeLog *pAnalyze);//ʱ��
	char*						GetCount(KAnalyzeLog *pAnalyze);//�ܴ���
	char*						GetMax(KAnalyzeLog *pAnalyze);//���
	char*						GetMin(KAnalyzeLog *pAnalyze);//��С
	char*						GetTotal(KAnalyzeLog *pAnalyze);//��ȡ����
	char*						GetDelay(KAnalyzeLog *pAnalyze);//��ȡ��ʱ
	char*						GetPlayerCostTime(KAnalyzeLog *pAnalyze);
	char*						GetNpc(KAnalyzeLog *pAnalyze);
	char*						GetAIType(KAnalyzeLog *pAnalyze);
	char*						GetActionKey(KAnalyzeLog *pAnalyze);
	char*						GetGameLoop(KAnalyzeLog *pAnalyze);
	char*						GetAIScriptID(KAnalyzeLog *pAnalyze);
	char*						GetAIEvent(KAnalyzeLog *pAnalyze);
	char*						GetState(KAnalyzeLog *pAnalyze);
	char*						GetRegion(KAnalyzeLog *pAnalyze);
	char*						GetregionTime(KAnalyzeLog *pAnalyze);
	char*						GetPlayer(KAnalyzeLog *pAnalyze);
	char*						GetFunction(KAnalyzeLog *pAnalyze);
	char*						GetScript(KAnalyzeLog *pAnalyze);
	char*						GetString(KAnalyzeLog *pAnalyze);
	char*						GetServer(KAnalyzeLog *pAnalyze);
	char*						GetWhy(KAnalyzeLog *pAnalyze);
	char*						DeleteLastZero(KAnalyzeLog *pAnalyze, char *Source);
	char*						GetMap(KAnalyzeLog *pAnalyze);
	char*						GetSubMap(KAnalyzeLog *pAnalyze);
	char*						GetLineNumber(KAnalyzeLog *pAnalyze);
	void						Test(KAnalyzeLog * pAnalyze, char *Source);

private:
	char*						m_InPutString;
	char*						m_Search;
	vector<char*>				m_LogType;
	LocalTime					LOCAL_TIME;
	char*						m_LogInformation;
	tm							TM;
	char*						sTypeFirst;
	char*						sTypeLast;
};

#endif

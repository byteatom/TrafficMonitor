#pragma once
#include"Common.h"
#include "afxcmn.h"

// CNetworkInfoDlg �Ի���

class CNetworkInfoDlg : public CDialog
{
	DECLARE_DYNAMIC(CNetworkInfoDlg)

public:
	CNetworkInfoDlg(MIB_IFROW network_info ,CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CNetworkInfoDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NETWORK_INFO_DIALOG };
#endif

	//void SetInOutBytes(unsigned int in_bytes, unsigned int out_bytes)
	//{
	//	m_in_bytes = in_bytes;
	//	m_out_bytes = out_bytes;
	//}
	unsigned int m_in_bytes;		//��ǰ�鿴�����������������ѽ����ֽ���
	unsigned int m_out_bytes;		//��ǰ�鿴�����������������ѷ����ֽ���

	SYSTEMTIME m_start_time;		//����������ʱ��

protected:

	MIB_IFROW m_network_info;		//��ǰ�鿴������������Ϣ
	wstring m_ip_address{ L"-.-.-.-" };		//IP��ַ
	wstring m_subnet_mask{ L"-.-.-.-" };	//��������
	wstring m_default_gateway{ L"-.-.-.-" };	//Ĭ������
	
	CListCtrl m_info_list;

	void GetIPAddress();	//��ȡIP��ַ
	void ShowInfo();

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

	virtual BOOL OnInitDialog();
};
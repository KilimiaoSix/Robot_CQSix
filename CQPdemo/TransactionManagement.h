#pragma once
#include "MsgSub.h"
class GroupMsgSub;

class TransactionManagement
{
public:
	static TransactionManagement * getInstance();
	//��ȡGroupMsgSubʵ��
	GroupMsgSub * getGroupMsgSubInstance();
private:
	TransactionManagement();
	~TransactionManagement();

	GroupMsgSub * m_groupMsgSub;
};


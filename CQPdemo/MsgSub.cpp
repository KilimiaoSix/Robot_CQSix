#include "stdafx.h"
#include "MsgSub.h"
#include "cqp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#define random(x) (rand()%x)
#include <string.h>
bool flag_debug = false;
int i = 0;
//�������趨ΪŮ�ͷ���
std::string RobotName_EN = "FiLa";
std::string RobotName_ZN = "����";

//����ȫ�ֱ��� ac   ��appmain.h �ж���
extern int ac;
bool Find(char* a,char* str)  
{
		if (strstr(str, a) != NULL)
		{	
			return true;
		}
		else
		{
			return false;
		}
}
/*bool OsuGroups(msg.fromGroup) {

}
*/
void GroupMsgSub::threadMain()
{
	while (!m_quit)
	{
		if (m_groupMsgBuffer.size() > 0)
		{
			m_mutex.lock();
			GroupMsg msg = m_groupMsgBuffer.front();
			m_groupMsgBuffer.pop();
			m_mutex.unlock();
		
			/*				ͨ	��				*/
			

			if (msg.msg=="!enter debug" &&msg.fromQQ == 1048597043)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "����debugģʽ");
				flag_debug = true;  //����debugģʽ
			}
			else if (msg.msg == "Сͩ��" && msg.fromQQ == 1048597043)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "������ã�");
			}
			else if (msg.msg == "Сͩ�����" && msg.fromQQ == 1048597043) 
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "���˺ã�����Ҳ������");
			}
			else if ((msg.msg == "Сͩ��"))
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "��?");
			}
			else if (msg.msg == "Сͩ����" && msg.fromQQ != 1048597043)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "�룬�벻Ҫ����������");
			}
			else if (msg.msg == "����Сͩ��" && msg.fromQQ != 1048597043)
			{
				i = random(4);
				if(i == 1)
					CQ_sendGroupMsg(ac, msg.fromGroup, "�롭�������ҵ�С��������");
				else if(i == 2)
					CQ_sendGroupMsg(ac, msg.fromGroup, "����������������");
				else if(i == 3)
				{
					CQ_sendGroupMsg(ac, msg.fromGroup, "��ͷ�᳤���ߵ�����");
				}
				else
				{
					CQ_sendGroupMsg(ac, msg.fromGroup, "������������������");
				}
			}
			else if (msg.msg == "Сͩ����" && msg.fromQQ == 1048597043)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "����Ҳ�ౣ�~~~~��");
			}
			else if (msg.msg == "����Сͩ��" && msg.fromQQ == 1048597043)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "���˵������������~~~");
			}
			else if(msg.msg == "Сͩ���������Ⱥ�������"&& msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "�������ǳ�DD��DD kimo");
			}
			else if ((msg.msg.find("ϲ��") != -1 || msg.msg.find("suki") != -1) && msg.fromGroup == 982711563 && msg.fromQQ == 51303014)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "DD kimo");
			}
			else if (msg.msg.find("cocomi suki") == -1 &&(msg.msg.find("ϲ��") != -1 || msg.msg.find("suki") != -1) && msg.fromGroup == 982711563 && msg.fromQQ == 51303014)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "DD kimo");
			}
			else if (msg.msg == "�� ���� ��" && msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "�� ���� ��");
			}
			else if (msg.msg == "Сͩ���������Ⱥ�����" && msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "tanko�˷������������������˵���Ҫ����");
			}	
			else if (msg.msg.find("cocomi suki") != -1 && msg.msg.find("suki") != -1 && msg.fromQQ == 1048597043 && msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "��������DD��");
			}
			else if (msg.msg == "Сͩ���������Ⱥ����ϰ�" && msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "���ϰ��Ůװ");
			}
			else if (msg.msg == "���˱���" && msg.fromGroup == 701962770)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "���˱���");
			}//�Ⱥ�����
			else if (msg.msg == "pjt�챬��" && msg.fromGroup == 701962770)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "pjt�챬�գ�");
			}//�Ⱥ��˽���
			else if (msg.msg == "���˽�Ⱥ�ø�ʲô" && msg.fromGroup == 701962770)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "��һ���ȿ�Ⱥ���棬�ڶ�����Ⱥ��Ƭ�����������շ������");
			}//������ʾ

		/*
				##############�����Ⱥ�##############			
		
																					*/

			////Dalou�ʵ�
			//if (msg.msg == "!hello" && msg.fromQQ == 1061566571) {
			//	CQ_sendGroupMsg(ac, msg.fromGroup, "��Ӧ����ʧ�ܣ�������");
			//	 

			//}

			//if (msg.fromGroup == 982711563) {
			//	if (msg.msg == "�� ���ϰ� ��") {
			//		CQ_sendGroupMsg(ac, msg.fromGroup, "�� ���ϰ� ��");
			//		 
			//	}
			//	else if (msg.msg == "�� ���ϰ� ��") {
			//		CQ_sendGroupMsg(ac, msg.fromGroup, "�� ���ϰ� ��");
			//		 
			//	}
			//	else if (msg.msg == "�Ⱥ����ϰ�") {
			//		int PICKS;
			//		PICKS = random(4);

			//		switch (PICKS){
			//		 case 1: {
			//			CQ_sendGroupMsg(ac, msg.fromGroup, "Ůװ  ���ϰ�  Ůװ");
			//			break;
			//		 }case 2: {
			//			CQ_sendGroupMsg(ac, msg.fromGroup, "��������� Ůװ����");
			//			break;
			//		 }case 3: {
			//			CQ_sendGroupMsg(ac, msg.fromGroup, "Kou��~~~~Ůװ����");
			//			break;

			//		 }
			//		 default:
			//		 {
			//			CQ_sendGroupMsg(ac, msg.fromGroup, "���ϰ��Ůװ��"); 
			//		 }
			//		}      
			//	}
			//	else if (msg.fromQQ == 416575098 && msg.msg == "ܳ") {
			//		CQ_sendGroupMsg(ac, msg.fromGroup, "ܳ�����ϰ� ܳ��");
			//		 
			//	}
			//	else if (msg.fromQQ == 416575098 && msg.msg == "��") {
			//		CQ_sendGroupMsg(ac, msg.fromGroup, "? Kou�� ?");
			//		 
			//	}
			//	else if (msg.fromQQ == 416575098 && msg.msg == "������") {
			//		CQ_sendGroupMsg(ac, msg.fromGroup, "??? Kou�� ???");
			//		 
			//	}
			//}

			///*else */ if (msg.msg == "!sleep") {
			//	//CQ_setGroupBan(ac, msg.fromGroup, fromQQ, 12000);
			//	CQ_sendGroupMsg(ac, msg.fromGroup, "���䤹�ߤʤ����������˘���");
			//	 
			//}

			//else if (msg.msg == "!����������") {
			//	//CQ_sendGroupMsg(ac, msg.fromGroup, "��˽��InkBot���������ID");
			//	CQ_sendGroupMsg(ac, msg.fromGroup, "�Զ�����ϵͳ������(�Уߩ�)������ȥ�����д�ˣ��鷳���ˣ�https://docs.qq.com/form/fill/DUmVZekRqRGJUYVRp");
			//	 
			//}
			//else if (msg.msg == "!github") { 
			//	CQ_sendGroupMsg(ac, msg.fromGroup, "https://github.com/inkchan2333/inkchan"); 
			//	 
			//}
			//else if (msg.msg == "!�����ϰ�") 
			//{
			//	CQ_sendGroupMsg(ac, msg.fromGroup, "��(>^��^<)�����ϰ����ص�ַ�� https://cola.sayobot.cn/inkcake/Minecraft%201.12.2%20IC2%20forge2768%20Shaders.zip");
			//	CQ_sendGroupMsg(ac, msg.fromGroup, "ллҹ���������֧�֣�");
			//	 
			//}



			/* 
			
								####  ����  ###
			
																		*/
			else if (msg.msg == "л��ΰ" || msg.msg == "��ΰ")
			{
				CQ_sendPrivateMsg(ac, 1048597043, "���˽��㣡");
			}
		
		}
		else
		{
			ThreadBase::mSleep(10);
		}
	}
	return;
}

GroupMsgSub::GroupMsgSub()
{
	m_quit = false;
}

GroupMsgSub::~GroupMsgSub()
{
}

void GroupMsgSub::start()
{
	m_quit = false;
	ThreadBase::start();
}

void GroupMsgSub::quite()
{
	ThreadBase::quit();
	m_quit = true;
}


void GroupMsgSub::pushMsg(int32_t msgId, int64_t fromGroup, int64_t fromQQ, std::string msg)
{
	//����������Ϣ����100��  ��ֱ�������µ�����Ϣ
	if (m_groupMsgBuffer.size() < 100)
	{
		m_mutex.lock();
		m_groupMsgBuffer.push(GroupMsg(msgId, fromGroup, fromQQ, msg));
		m_mutex.unlock();
	}
}



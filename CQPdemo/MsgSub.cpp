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
			

			if (msg.msg == "!github")  //���뿪Դ
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "GitHub����:https://github.com/KilimiaoSix/Robot_CQSix.git Ŀǰ�汾�ǣ�1.0.3");
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
				if (i == 1)
					CQ_sendGroupMsg(ac, msg.fromGroup, "�롭�������ҵ�С��������");
				else if (i == 2)
					CQ_sendGroupMsg(ac, msg.fromGroup, "����������������");
				else if (i == 3)
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
			else if (msg.msg == "Сͩ���������Ⱥ�������" && msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "�������ǳ�DD��DD kimo");
			}
			else if ((msg.msg.find("ϲ��") != -1 || msg.msg.find("suki") != -1) && msg.fromGroup == 982711563 && msg.fromQQ == 51303014)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "DD kimo");
			}
			else if (msg.msg.find("cocomi suki") == -1 && (msg.msg.find("ϲ��") != -1 || msg.msg.find("suki") != -1) && msg.fromGroup == 982711563 && msg.fromQQ == 51303014)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "DD kimo");
			}
			else if (msg.msg == "�� ���� ��" && msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "�� ���� ��");
			}
			else if (msg.msg.find("cocomi suki") != -1 && msg.msg.find("suki") != -1 && msg.fromQQ == 1048597043 && msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "��������DD��");
			}
			else if (msg.msg == "Сͩ���������Ⱥ����ϰ�" && msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "���ϰ��Ůװ");
			}
			else if (msg.msg == "Сͩ�����������������ô��" && msg.fromGroup == 765455518)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "��һ�����밲װJava���ڶ������빺������ٷ����ʷ�������������������������װmod�����Ĳ����·�����ֱ�ӽ����ɷ�����дȺ�ļ��ı�ע�������лл��������������뿴Ⱥ����");
			}
			else if (msg.msg == "!MC" && msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac,msg.fromGroup,"Ҫ��MC�ļ�Ⱥ765455518");
			}
			else if (msg.msg == "!������ע��" && msg.fromGroup == 765455518)  //���ע�ỹû�㶨���Ե�
				CQ_sendGroupMsg(ac, msg.fromGroup, "�һ�û�㶨���ע�ᣬҪע����Լ���� https://docs.qq.com/sheet/DZEJQb3dCb0piRXF0?preview_token=&coord=H7%24H7%240%240%240%240&tab=BB08J2");
			else if (msg.msg == "!��������ַ" && msg.fromGroup == 765455518)
				CQ_sendGroupMsg(ac, msg.fromGroup, "�ɷ�������[inkcake.sayobot.cn:25565] �·������� [inkcake.sayobot.cn:23333]");
			//----------------------�ָ���-----------------------------------//
			//---------------------------------------------------------------//
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



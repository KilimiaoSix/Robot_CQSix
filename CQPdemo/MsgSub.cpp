#include "stdafx.h"
#include "MsgSub.h"
#include "cqp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#define random(x) (rand()%x)
#include <string.h>
bool flag_debug = false;
int i = 0;
//�������趨ΪŮ�ͷ���
std::string RobotName_EN = "FiLa";
std::string RobotName_ZN = "����";

//����ȫ�ֱ��� ac   ��appmain.h �ж���
extern int ac;
/*bool OsuGroups(msg.fromGroup) {

}
*/
void TimeJudge(SYSTEMTIME &st,GroupMsg &msg,bool master_t)
{
	if (st.wHour >= 5 && st.wHour < 11)  //����ʱ��
	{
		if (master_t)
		{
			CQ_sendGroupMsg(ac, msg.fromGroup, "���ˣ����Ϻã�����Ҳ�����Ŭ�����Ͱ���~");
		}
		else
		{
			CQ_sendGroupMsg(ac, msg.fromGroup, "���Ϻ������µ�һ�����������~��");
		}
	}
	else if (st.wHour >= 11 && st.wHour < 15)  //����ʱ��
	{
		if (master_t)
		{
			CQ_sendGroupMsg(ac, msg.fromGroup, "���ˣ�����ã��緹�кúó�����~");
		}
		else
		{
			CQ_sendGroupMsg(ac, msg.fromGroup, "�簲desu~����");
		}
	}
	else if (st.wHour >= 15 && st.wHour < 18)  //����ʱ��
	{
		if (master_t)
		{
			CQ_sendGroupMsg(ac, msg.fromGroup, "���ˣ�����ã�~");
		}
		else
		{
			CQ_sendGroupMsg(ac, msg.fromGroup, "�������~��");
		}
	}
	else if (st.wHour >= 18 && st.wHour < 23)  //����ʱ��
	{
		if (master_t)
		{
			CQ_sendGroupMsg(ac, msg.fromGroup, "���ˣ����Ϻã�~");
		}
		else
		{
			CQ_sendGroupMsg(ac, msg.fromGroup, "���������Ϻ�desu��~");
		}
	}
	else  //��ҹ
	{
		if (master_t)
		{
			CQ_sendGroupMsg(ac, msg.fromGroup, "���ˣ��ܳ���Ŷ~~����ȥ˯��Ⱥ�����ҿ���");
		}
		else
		{
			CQ_sendGroupMsg(ac, msg.fromGroup, "zzzzzzzzzzz��������~~");
		}
	}
}
//����ÿ����к���
void Say_Hello(SYSTEMTIME& st, GroupMsg& msg, bool master_t)
{
	if (msg.msg == "Сͩ�������Ϻ�")
	{
		if (st.wHour >= 5 && st.wHour < 11)
		{
			if (master_t)
				CQ_sendGroupMsg(ac, msg.fromGroup, "�������Ϻã��µ�һ��Ҳһ����Ͱɣ�");
			else
				CQ_sendGroupMsg(ac, msg.fromGroup, "���Ϻ�desu�����µ�һ��ҲҪ�úù���Ŷ��");
		}
		else
		{
			if (master_t)
				CQ_sendGroupMsg(ac, msg.fromGroup, "���ˣ����ڿɲ�������Ŷ~��");
			else
				CQ_sendGroupMsg(ac, msg.fromGroup, "���ڿɲ�������Ŷ��");
		}
	}
	else if (msg.msg == "Сͩ���������")
	{
		if (st.wHour >= 11 && st.wHour < 15)
		{
			if (master_t)
				CQ_sendGroupMsg(ac, msg.fromGroup, "���ˣ�����ã�Ҫ�úó��緹Ȼ��úõ�˯һ��Ŷ��");
			else
				CQ_sendGroupMsg(ac, msg.fromGroup, "�簲~~~��");
		}
		else
		{
			if (master_t)
				CQ_sendGroupMsg(ac, msg.fromGroup, "���ˣ����ڿɲ�������Ŷ~˯�Ժ�����");
			else
				CQ_sendGroupMsg(ac, msg.fromGroup, "������");
		}
	}
	else if (msg.msg == "Сͩ���������")
	{
		if (st.wHour >= 15 && st.wHour < 18)
		{
			if (master_t)
				CQ_sendGroupMsg(ac, msg.fromGroup, "���ˣ�����ã�Ҫ�ú�ȥѧϰ��������Ŷ��");
			else
				CQ_sendGroupMsg(ac, msg.fromGroup, "����ã�Ҫ�ú�ȥѧϰ��������Ŷ��");
		}
		else
		{
			if (master_t)
				CQ_sendGroupMsg(ac, msg.fromGroup, "���ˣ����ڿɲ�������Ŷ~mofumofu~");
			else
				CQ_sendGroupMsg(ac, msg.fromGroup, "��Ͳ���������Ŷ~");
		}

	}
	else if (msg.msg == "Сͩ�������Ϻ�")
	{
		if (st.wHour >= 15 && st.wHour < 18)
		{
			if (master_t)
				CQ_sendGroupMsg(ac, msg.fromGroup, "���ˣ����Ϻã�");
			else
				CQ_sendGroupMsg(ac, msg.fromGroup, "���Ϻ�Ŷ~��");
		}
		else
		{
			if (master_t)
				CQ_sendGroupMsg(ac, msg.fromGroup, "���ˣ����ڿɲ�������Ŷ~��~");
			else
				CQ_sendGroupMsg(ac, msg.fromGroup, "emmmm����������Ŷ~");
		}
	}
	else if (msg.msg == "Сͩ������")
	{
		if (st.wHour >= 23 || (st.wHour >= 0 && st.wHour < 5))
		{
			if (master_t)
				CQ_sendGroupMsg(ac, msg.fromGroup, "���ˣ���������һ��Ҳ�����ˣ��ú���ϢŶ��");
			else
				CQ_sendGroupMsg(ac, msg.fromGroup, "����");
		}
		else
		{
			if (master_t)
				CQ_sendGroupMsg(ac, msg.fromGroup, "���ˣ����ڿɲ���˯����ʱ��Ŷ");
			else
				CQ_sendGroupMsg(ac, msg.fromGroup, "��˯�ˣ�̫��ɹƨ���ˣ�");
		}
	}
	
}
void Time_Message(SYSTEMTIME& st, GroupMsg& msg)
{
	char str[200];
	sprintf(str, "���ڵ�ʱ���ǣ�%d ʱ %d ��", st.wHour, st.wMinute);
	CQ_sendGroupMsg(ac,msg.fromGroup,str);
}
void GroupMsgSub::threadMain()
{
	while (!m_quit)
	{
		if (m_groupMsgBuffer.size() > 0)
		{
			m_mutex.lock();
			SYSTEMTIME st = { 0 };
			GetLocalTime(&st);
			GroupMsg msg = m_groupMsgBuffer.front();
			m_groupMsgBuffer.pop();
			m_mutex.unlock();
		
			/*				ͨ	��				*/
			

			if (msg.msg == "!github")  //���뿪Դ
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "GitHub����:https://github.com/KilimiaoSix/Robot_CQSix.git Ŀǰ�汾�ǣ�1.0.4");
			}
			else if (msg.msg == "!�ʿ�༭")
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "�����https://docs.qq.com/sheet/DZHB4SVRvaGtEeWVq?preview_token=&coord=C14%24C14%240%240%240%240&tab=BB08J2");
				CQ_sendGroupMsg(ac, msg.fromGroup, "��Ҫ��Щ���߰���Ķ���Ŷ��");
			}
			else if (msg.msg == "Сͩ��" && msg.fromQQ == 1048597043)
			{
				TimeJudge(st,msg,true);
			}
			else if (msg.msg == "Сͩ�����" && msg.fromQQ == 1048597043)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "���˺ã�����Ҳ������");
			}
			else if ((msg.msg == "Сͩ��"))
			{
				TimeJudge(st, msg, false);
			}
			else if (msg.msg == "Сͩ����" && msg.fromQQ != 1048597043)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "�룬�벻Ҫ����������");
			}
			else if (msg.msg == "����Сͩ��" && msg.fromQQ != 1048597043)
			{
				i = random(4);
				if (i == 1)
					CQ_sendGroupMsg(ac, msg.fromGroup, "mofumofu~��");
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
			else if (msg.msg == "Сͩ����ɰ�" && msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "wwwwwwwwwwwww");
			}
			else if (msg.msg == "Сͩ����" && msg.fromQQ == 1048597043)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "����Ҳ�ౣ�~~~~��");
			}
			else if (msg.msg == "����Сͩ��" && msg.fromQQ == 1048597043)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "���˵�mofumofu~~~");
			}
			else if (msg.msg == "Сͩ���������Ⱥ�������" && msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "������ʲôʱ��Ůװ��������");
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
			else if (msg.msg.find("cocomi suki") == -1 && msg.msg.find("suki") != -1 && msg.fromQQ == 1048597043 && msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "��������DD��");
			}
			else if (msg.msg == "Сͩ���������Ⱥ����ϰ�" && msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "���ϰ��Ůװ");
			}
			else if (msg.msg == "Сͩ����������MC��ô��" && msg.fromGroup == 765455518)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "��һ�����밲װJava���ڶ������빺������ٷ����ʷ�������������������������װmod�����Ĳ����·�����ֱ�ӽ����ɷ�����дȺ�ļ��ı�ע�������лл��������������뿴Ⱥ����");
			}
			else if (msg.msg == "!MC" && msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "Ҫ��MC�ļ�Ⱥ765455518");
			}
			else if (msg.msg == "�Ⱥ�������" && msg.fromGroup == 982711563)
			{
				int i = random(2);
				if(i == 1)
					CQ_sendGroupMsg(ac, msg.fromGroup, "[CQ:image,file=1.jpg]");
				else
					CQ_sendGroupMsg(ac, msg.fromGroup, "[CQ:image,file=2.jpg]");
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
			else if (msg.msg == "Сͩ�������ڼ�����" || msg.msg == "!time" || msg.msg == "!ʱ��")
			{
				Time_Message(st,msg);
			}
			//////���к���
			else if (msg.msg == "Сͩ�������Ϻ�" || msg.msg == "Сͩ���������" || msg.msg == "Сͩ���������" || msg.msg == "Сͩ�������Ϻ�" || msg.msg == "Сͩ������")
			{
				if (msg.fromQQ == 1048597043)
				{
					Say_Hello(st, msg, true);
				}
				else
				{
					Say_Hello(st, msg, false);
				}
			 }
			else if (msg.msg == "Сͩ��ȰȰ���ϰ�" && msg.fromGroup == 982711563)
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "kou�����Ǹ���Ůװ�����ò��á�");
			}
			else if (msg.msg == "����˻��˻��" && (msg.fromGroup == 982711563 ||  msg.fromGroup == 765455518))
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "����˻��˻��");
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



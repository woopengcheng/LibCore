// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� LUA_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// LUA_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef LUA_EXPORTS
#define LUA_API __declspec(dllexport)
#else
#define LUA_API __declspec(dllimport)
#endif

// �����Ǵ� lua.dll ������
class LUA_API Clua {
public:
	Clua(void);
	// TODO: �ڴ�������ķ�����
};

extern LUA_API int nlua;

LUA_API int fnlua(void);

#include <windows.h>
#include <string>

enum { ID_DISPLAY=1000, ID_DIGIT0=1100, ID_DOT=1110, ID_ADD=1200, ID_SUB, ID_MUL, ID_DIV, ID_EQ, ID_CLR };

HWND g_display;
std::wstring cur, acc;
wchar_t op=L'\0';
bool err=false;

inline void show(const std::wstring&s){ SetWindowTextW(g_display,s.c_str()); }
inline void reset(){ cur.clear(); acc.clear(); op=L'\0'; err=false; show(L"0"); }

std::wstring tidy(const std::wstring&s){ size_t p=s.find(L'.'); if(p==std::wstring::npos) return s; size_t e=s.size(); while(e>p+1&&s[e-1]==L'0') e--; if(e>p&&s[e-1]==L'.') e--; return s.substr(0,e); }

bool eval(const std::wstring&a,const std::wstring&b,wchar_t o,std::wstring&out){
    try{
        double da=std::stod(a), db=std::stod(b), r=0;
        if(o==L'+') r=da+db; else if(o==L'-') r=da-db; else if(o==L'*') r=da*db; else if(o==L'/'){ if(db==0) return false; r=da/db; } else return false;
        wchar_t buf[128]; swprintf(buf,128,L"%.15g",r); out=tidy(buf); return true;
    }catch(...){ return false; }
}

void pushDigit(wchar_t d){ if(err) reset(); if(cur==L"0") cur.clear(); cur.push_back(d); show(cur); }
void pushDot(){ if(err) reset(); if(cur.find(L'.')==std::wstring::npos){ if(cur.empty()) cur=L"0"; cur.push_back(L'.'); show(cur);} }
void pushOp(wchar_t o){ if(err) reset(); if(acc.empty()){ acc=cur.empty()?L"0":cur; cur.clear(); op=o; return; } if(!cur.empty()){ std::wstring r; if(!eval(acc,cur,op,r)){ err=true; show(L"Error"); return;} acc=r; show(acc); cur.clear(); } op=o; }
void equals(){ if(err) { reset(); return; } if(acc.empty()||op==L'\0'||cur.empty()) return; std::wstring r; if(!eval(acc,cur,op,r)){ err=true; show(L"Error"); return;} acc=r; cur.clear(); op=L'\0'; show(acc); }

HWND btn(HWND p,int id,const wchar_t*t,int x,int y,int w,int h){ return CreateWindowW(L"BUTTON",t,WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,x,y,w,h,p,(HMENU)(INT_PTR)id,GetModuleHandleW(NULL),NULL); }

LRESULT CALLBACK WndProc(HWND h,UINT m,WPARAM w,LPARAM l){
    switch(m){
    case WM_CREATE:{
        g_display=CreateWindowW(L"EDIT",L"0",WS_CHILD|WS_VISIBLE|ES_RIGHT|ES_AUTOHSCROLL|WS_BORDER|ES_READONLY,10,10,280,35,h,(HMENU)(INT_PTR)ID_DISPLAY,GetModuleHandleW(NULL),NULL);
        const wchar_t* labels[][4]={{L"7",L"8",L"9",L"/"},{L"4",L"5",L"6",L"*"},{L"1",L"2",L"3",L"-"},{L"0",L".",L"=",L"+"}};
        int ids[][4]={{ID_DIGIT0+7,ID_DIGIT0+8,ID_DIGIT0+9,ID_DIV},{ID_DIGIT0+4,ID_DIGIT0+5,ID_DIGIT0+6,ID_MUL},{ID_DIGIT0+1,ID_DIGIT0+2,ID_DIGIT0+3,ID_SUB},{ID_DIGIT0+0,ID_DOT,ID_EQ,ID_ADD}};
        int bx=10,by=55,bw=65,bh=45,g=10; for(int r=0;r<4;r++) for(int c=0;c<4;c++) btn(h,ids[r][c],labels[r][c],bx+c*(bw+g),by+r*(bh+g),bw,bh);
        btn(h,ID_CLR,L"C",bx,by+4*(bh+g),bw*4+g*3,bh);
        reset();
        return 0;
    }
    case WM_COMMAND:{
        int id=LOWORD(w);
        if(id>=ID_DIGIT0&&id<ID_DIGIT0+10) pushDigit(L'0'+(id-ID_DIGIT0));
        else if(id==ID_DOT) pushDot();
        else if(id==ID_ADD) pushOp(L'+');
        else if(id==ID_SUB) pushOp(L'-');
        else if(id==ID_MUL) pushOp(L'*');
        else if(id==ID_DIV) pushOp(L'/');
        else if(id==ID_EQ) equals();
        else if(id==ID_CLR) reset();
        return 0;
    }
    case WM_DESTROY: PostQuitMessage(0); return 0;
    }
    return DefWindowProcW(h,m,w,l);
}

int WINAPI wWinMain(HINSTANCE hi,HINSTANCE, PWSTR, int n){
    const wchar_t* cls=L"CalcWnd"; WNDCLASSW wc={}; wc.lpfnWndProc=WndProc; wc.hInstance=hi; wc.lpszClassName=cls; wc.hCursor=LoadCursor(NULL,IDC_ARROW); RegisterClassW(&wc);
    HWND hw=CreateWindowExW(0,cls,L"Simple Calculator",WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_MINIMIZEBOX,CW_USEDEFAULT,CW_USEDEFAULT,310,360,NULL,NULL,hi,NULL); if(!hw) return 0; ShowWindow(hw,n); UpdateWindow(hw);
    MSG msg; while(GetMessageW(&msg,NULL,0,0)){ TranslateMessage(&msg); DispatchMessageW(&msg);} return 0;
}
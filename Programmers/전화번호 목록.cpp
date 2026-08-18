#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    // 사전순 정렬 시 접두어는 반드시 바로 앞에 위치
    sort(phone_book.begin(), phone_book.end());
    
    for (int i = 0; i < phone_book.size() - 1; i++) {
        // 뒷 번호가 앞 번호로 시작하면 접두어 존재
        if (phone_book[i + 1].compare(0, phone_book[i].size(), phone_book[i]) == 0)
            return false;
    }
    return true;
}
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode *bottom;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct List {
    int val,key;
    List *right;
    List *left;
    List() : val(0), right(nullptr) , left(nullptr) {}
    List(int x) : val(x), right(nullptr) , left(nullptr) {}
    List(int x, List *next) : val(x), right(nullptr) , left(nullptr) {}
};
struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode() : val(0), left(nullptr), right(nullptr) {}
         TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
         TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     };
ListNode * createListNode(vector<int> arr){

    ListNode * start = NULL;
    ListNode * end = NULL;
    for(int i =0;i<arr.size();i++){
        ListNode * temp = new ListNode(arr[i]);
        if(start == NULL)
            end = start = temp;
        else {
            end->next = temp;
            end = end->next;
        }
    }
    return start;
}
void printListNode(ListNode* head){
    while (head) {
        cout << head->val << "\t";
        head = head->next;
    }
}
ListNode * reverse(ListNode * head){
    ListNode * start = head;
    ListNode * end = head;
    head = head->next;
    end->next = NULL;
    while(head){
        end->next = head;
        head = head->next;
        end = end->next;
    }
    return start;
}
int NodeCount(ListNode * start){
    int count = 0;
    while (start){
        count++;
        start = start->next;
    }
    return count;
}
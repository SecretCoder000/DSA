using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode *bottom;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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

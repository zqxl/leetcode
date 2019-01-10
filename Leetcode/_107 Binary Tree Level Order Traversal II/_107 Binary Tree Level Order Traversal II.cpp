#include<stdio.h>
#include<malloc.h>

struct TreeNode {
	int val;
	struct TreeNode *left = NULL;
	struct TreeNode *right = NULL;

	TreeNode(int x) {
		val = x;
	}
};


// ************************************        层次遍历法4ms，去掉了频繁的realloc。如果想兼顾空间和时间的话，可以考虑每次将分配的空间*2     ***************************
int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
	// 创建一直二叉树指针数组作为队列
	struct TreeNode *qu[10240];
	// 创建一个相同结构的数组来记录每个入队元素的深度,dc记录当前出队元素的深度
	int d[10240], dc=0;
	//创建一个二维数作为输出
	int **r = (int**)malloc(4096*sizeof(int*));
	r[0] = (int*)malloc(4096*sizeof(int));
	// 记录返回数组的大小
	*returnSize = 1;
	*columnSizes = (int*)malloc(4096 * sizeof(int));
	(*columnSizes)[0] = 0;
	// 队列起始和终止下标，s为第一个元素e-1为最后一个元素
	int s = 0, e = 0;
	if (root == NULL) {
		r = (int**)malloc(0 * sizeof(int*));
		*returnSize = 0;
		(*columnSizes)[0] = 0;
		return 0;
	}
	else {
		d[e] = 1;
		qu[e++] = root;
	}
	while (e - s > 0) {
		// 出队
		dc = d[s];
		root = qu[s++];

		// 访问
		if (dc == *returnSize) {
			// 更新该行长度
			((*columnSizes)[*returnSize-1])++;
			// 保存该节点
			r[dc-1][(*columnSizes)[*returnSize-1]-1] = root->val;
		}
		else {
			// 更新行数
			(*returnSize)++;
			//r = (int**)realloc(r, *returnSize * sizeof(int*));

			// 更新该行长度
			(*columnSizes)[*returnSize-1] =1;
			// 重新分配该行的内存
			r[dc-1] = (int*)malloc(4096 * sizeof(int));
			// 保存该节点
			r[dc-1][(*columnSizes)[*returnSize-1]-1] = root->val;
		}

		// 左右孩子入队
		if (root->left) {
			d[e] = dc + 1;
			qu[e++] = root->left;
		}
		if (root->right) {
			d[e] = dc + 1;
			qu[e++] = root->right;
		}
	}

	// 反转数组
	int **rr = (int**)malloc(*returnSize * sizeof(int*));
	int temp = 0;
	for (int i = 0; i < *returnSize; i++) {
		rr[i] = r[*returnSize - i - 1];
		// 反转columSize
		if(i<*returnSize/2){
			temp = (*columnSizes)[i];
			(*columnSizes)[i] = (*columnSizes)[*returnSize - i - 1];
			(*columnSizes)[*returnSize - i - 1]  = temp;
		}
	}
	//释放内存
	free(r);
	return rr;
}

// ****************************************************        层次遍历法32ms，频繁realloc牺牲了速度，充分利用了空间      *****************************************************************
int** levelOrderBottom2(struct TreeNode* root, int** columnSizes, int* returnSize) {
	// 创建一直二叉树指针数组作为队列
	struct TreeNode *qu[10240];
	// 创建一个相同结构的数组来记录每个入队元素的深度,dc记录当前出队元素的深度
	int d[10240], dc = 0;
	//创建一个二维数作为输出
	int **r = (int**)malloc(1 * sizeof(int*));
	r[0] = (int*)malloc(sizeof(int));
	// 记录返回数组的大小
	*returnSize = 1;
	*columnSizes = (int*)malloc(1 * sizeof(int));
	(*columnSizes)[0] = 0;
	// 队列起始和终止下标，s为第一个元素e-1为最后一个元素
	int s = 0, e = 0;
	if (root == NULL) {
		r = (int**)malloc(0 * sizeof(int*));
		*returnSize = 0;
		(*columnSizes)[0] = 0;
		return 0;
	}
	else {
		d[e] = 1;
		qu[e++] = root;
	}
	while (e - s > 0) {
		// 出队
		dc = d[s];
		root = qu[s++];

		// 访问
		if (dc == *returnSize) {
			// 更新该行长度
			((*columnSizes)[*returnSize - 1])++;
			// 重新分配该行的内存
			r[dc - 1] = (int*)realloc(r[dc - 1], (*columnSizes)[*returnSize - 1] * sizeof(int));
			// 保存该节点
			r[dc - 1][(*columnSizes)[*returnSize - 1] - 1] = root->val;
		}
		else {
			// 更新行数
			(*returnSize)++;
			r = (int**)realloc(r, *returnSize * sizeof(int*));

			// 为columnSizes重新分配内存
			*columnSizes = (int*)realloc(*columnSizes, (*returnSize) * sizeof(int));
			// 更新该行长度
			(*columnSizes)[*returnSize - 1] = 1;
			// 重新分配该行的内存
			r[dc - 1] = (int*)malloc((*columnSizes)[*returnSize - 1] * sizeof(int));
			// 保存该节点
			r[dc - 1][(*columnSizes)[*returnSize - 1] - 1] = root->val;
		}

		// 左右孩子入队
		if (root->left) {
			d[e] = dc + 1;
			qu[e++] = root->left;
		}
		if (root->right) {
			d[e] = dc + 1;
			qu[e++] = root->right;
		}
	}

	// 反转数组
	int **rr = (int**)malloc(*returnSize * sizeof(int*));
	int temp = 0;
	for (int i = 0; i < *returnSize; i++) {
		rr[i] = r[*returnSize - i - 1];
		// 反转columSize
		if (i<*returnSize / 2) {
			temp = (*columnSizes)[i];
			(*columnSizes)[i] = (*columnSizes)[*returnSize - i - 1];
			(*columnSizes)[*returnSize - i - 1] = temp;
		}
	}
	//释放内存
	free(r);
	return rr;
}



// *********************************************************************        他人 4ms      *****************************************************************************
// 0ms
int GetdepthofTree(struct TreeNode* root) {
	if (!root) return 0;
	int left = GetdepthofTree(root->left);
	int right = GetdepthofTree(root->right);
	if (left > right)
		return left + 1;
	else
		return right + 1;
}


int** levelOrderBottom1(struct TreeNode* root, int** columnSizes, int* returnSize) {
	if (!root) {
		return NULL;
	}
	//获取二叉树的深度，最大层数或者说
	int depth = *returnSize = GetdepthofTree(root);

	//ret是一个指向一个二维数组的指针，这一块地址是我们自己开辟的，需要malloc
	int** ret = (int**)malloc(depth * sizeof(int*));

	//columnSizes是一个指向指针的指针，这个地址已经指定了，就是说这个地址了存放的下一个地址已经确定了，但是下一个地址里存放的还是地址，这个地址任然不确定，那么就需要malloc了
	//*columnSizes是一个指向一个一维数组的指针，数组的大小也是depth

	*columnSizes = (int*)malloc(depth * sizeof(int));
	int front = 0, back = 0;
	struct TreeNode* queue[10000];
	queue[back++] = root;
	while (front < back) {
		int start = front, end = back;
		(*columnSizes)[--depth] = end - start;
		front = end;
		//开始的时候我们只给了ret的地址，因为ret是一个二维数组的起始地址，但是这个二维数组里面的一维数组的地址并没有确定，就需要malloc来确定
		ret[depth] = (int*)malloc((end - start) * sizeof(int));
		for (int i = start; i<end; i++) {
			ret[depth][i - start] = queue[i]->val;
			if (queue[i]->left) queue[back++] = queue[i]->left;
			if (queue[i]->right) queue[back++] = queue[i]->right;
		}
	}
	return ret;
}

int main() {
	struct TreeNode t3(3), t9(9), t20(20), t15(15), t7(7);
	t3.left = &t9;
	t3.right = &t20;
	t20.left = &t15;
	t20.right = &t7;

	int* columnSizes;
	int returnSize;
	levelOrderBottom(&t3, &columnSizes, &returnSize);
	return 0;
}

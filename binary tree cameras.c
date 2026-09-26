int cameraCount = 0;

// Helper function returning node states:
// 0: Needs a camera
// 1: Has a camera
// 2: Covered (no camera needed)
int dfs(struct TreeNode* node) {
    if (node == NULL) {
        return 2;
    }
    
    int left = dfs(node->left);
    int right = dfs(node->right);
    
    if (left == 0 || right == 0) {
        cameraCount++;
        return 1;
    }
    if (left == 1 || right == 1) {
        return 2;
    }
    
    return 0;
}

int minCameraCover(struct TreeNode* root) {
    cameraCount = 0;
    if (dfs(root) == 0) {
        cameraCount++;
    }
    return cameraCount;
}

from tkinter import *
import networkx as nx
from networkx import bfs_tree
import matplotlib.pyplot as plt
import os
# 创建二叉树类
class BinaryTree:
	def __init__(self, value):
		self.value = value
		self.left = None
		self.right = None
#序列化与反序列化
class Codec:
    def serialize(self, root):
        # 如果根节点为空，返回空字符串
        if not root:
            return "[]"
        # 初始化结果列表和队列
        res = []
        quence = [root]
        # 当队列不为空时，循环继续
        while quence:
            # 从队列中取出一个节点
            r = quence.pop(0)
            # 如果节点不为空，将节点的值添加到结果列表中
            if r:
                res.append(str(r.value))
                # 将节点的左右子节点添加到队列中
                quence.append(r.left)
                quence.append(r.right)
            # 如果节点为空，将"None"添加到结果列表中
            else:
                res.append("None")
        # 返回结果字符串，用逗号分隔
        return "[" + ",".join(res) + "]"

    def deserialize(self, data):
        # 如果数据为空或为"[]"，返回空
        if not data or data == "[]":
            return
        # 将数据字符串解码为列表
        data = data[1:-1].split(',')
        # 初始化根节点和队列
        i = 1
        root = BinaryTree(int(data[0]))
        quence = [root]
        # 当队列不为空时，循环继续
        while quence:
            # 从队列中取出一个节点
            node = quence.pop(0)
            # 如果列表中当前元素不为"None"，则新建一个节点，并将其作为节点的左子节点
            if not data[i] == "None":
                node.left = BinaryTree(int(data[i]))
                quence.append(node.left)
            i += 1
            # 如果列表中当前元素不为"None"，则新建一个节点，并将其作为节点的右子节点
            if not data[i] == "None":
                node.right = BinaryTree(int(data[i]))
                quence.append(node.right)
            i += 1
        # 返回根节点
        return root
#写入文件
def write_to_file(root, file_path):
    if not os.path.exists(file_path):
        with open(file_path, 'w') as file:
            pass
    with open(file_path, 'w') as file:
        file.write(code.serialize(root))
#读取文件 
def read_from_file(file_path):
    if not os.path.exists(file_path):
        return None
    with open(file_path, 'r') as file:
        data = file.read()
        return code.deserialize(data)
# 增加节点
def add_node(root, value): 
    if root is None:
        return BinaryTree(value)
    else:
        if value < root.value:
            root.left = add_node(root.left, value)
        if value > root.value:
            root.right = add_node(root.right, value)
        if value == root.value:
            return root
        return root
# 删除节点
def delete_node(root, value):
        if root is None:
            return root
        if root.value == value:
            return root.left if root.left else root.right  
        root.left = delete_node(root.left, value)
        root.right = delete_node(root.right, value)
        return root

# 非递归的层次遍历
def level_order_traversal(root):
    # 如果根节点为空，返回空列表
    if root is None:
        return []
    # 初始化结果列表和队列
    result = []
    queue = [(root, root.value)]  # 添加一个元组，包含节点和节点的值    
    # 当队列不为空时，循环继续
    while queue:
        # 从队列中取出一个节点和节点的值
        node, value = queue.pop(0)
        # 将节点的值添加到结果列表中
        result.append(value)
        # 如果左子节点不为空，将其添加到队列中，并添加一个元组，包含节点和节点的值
        if node.left:
            queue.append((node.left, node.left.value))
        # 如果右子节点不为空，将其添加到队列中，并添加一个元组，包含节点和节点的值
        if node.right:
            queue.append((node.right, node.right.value))   
    # 返回结果列表
    return result
#可视化层次遍历的过程
def visualize_level_order(G, pos):  
    global tree
    update_graph(tree)
    if not tree :
        result_text = Text(Root)
        result_text.insert(END,"树为空")
        result_text.place(relx=0.1, rely=0.8, relwidth=0.8, relheight=0.1)
        return
    #如果图为空，还没有绘制
    if not G:
        create_graph(tree,pos)
    # 获取层次遍历的节点列表
    level_order = level_order_traversal(tree)    
    # 层次遍历并更新节点颜色
    for node in level_order:
        G.nodes[node]['color'] = 'red'
        nx.draw_networkx(G, pos, nodelist=[node], node_color=G.nodes[node]['color'], node_size=500)
        plt.axis('off')  # 不显示坐标轴
        plt.show()  # 显示图形
        plt.pause(0.5)#代替sleep()防止卡顿
    #弹出遍历结果文本框
    result_label = Label(Root, text="层次遍历结果:")
    result_label.place(relx=0.1, rely=0.7, relwidth=0.8, relheight=0.1)
    result_text = Text(Root)
    result_text.insert(END,str(level_order_traversal(tree)))
    result_text.place(relx=0.1, rely=0.8, relwidth=0.8, relheight=0.1)
#绘制图像
def create_graph(node, pos, layer=1, x=0, y=0):
    if node:
        # 绘制节点
        pos[node.value] = (x, y)
        G.add_node(node.value)#先把结点加入图中，防止后续的程序出错
        # 绘制左子树
    if node.left:
        create_graph(node.left, pos, layer+1, x-1/layer, y-1)
            # 绘制边
        G.add_edge(node.value, node.left.value)
        # 绘制右子树
    if node.right:
        create_graph(node.right, pos, layer+1, x+1/layer, y-1)
        # 绘制边
        G.add_edge(node.value, node.right.value)
#实时显示
def update_graph(root,value=None):
    global tree, G, pos
    if value is not None:
            tree = add_node(root, value)
            G.add_node(value)
    plt.close()
    create_graph(tree, pos)
    fig, ax = plt.subplots()
    nx.draw_networkx(G, pos, ax=ax, node_size=700)
    plt.show()
    write_to_file(tree,file_path)
def update_graph_del(root,value=None):
    global tree, G, pos
    create_graph(tree, pos)
    if value is not None:
            root = tree
            tree = delete_node(root, value)
            # if tree == root: 
            #     result_text = Text(Root)
            #     result_text.insert(END,"未找到该节点")
            #     result_text.place(relx=0.1, rely=0.8, relwidth=0.8, relheight=0.1)
            G.remove_node(value)
    plt.close()
    create_graph(tree, pos)
    fig, ax = plt.subplots()
    nx.draw_networkx(G, pos, ax=ax, node_size=700)
    plt.show()
    write_to_file(tree,file_path)
# 创建有向图
G = nx.DiGraph()
# 创建节点位e置字典
pos = {}
# 创建二叉树e
code=Codec()
file_path = 'desings_DSA/tree.txt'
tree=read_from_file(file_path)
#GUI界面
Root = Tk()
Root.title("二叉树的层次遍历")
Root.geometry("600x500")
# 创建输入框和按钮
inp1 = Entry(Root)
inp1.place(relx=0.1, rely=0.2, relwidth=0.8, relheight=0.1)
inp2 = Entry(Root)
inp2.place(relx=0.1, rely=0.4,  relwidth=0.8, relheight=0.1)
bt1 = Button(Root, text="增加结点", command=lambda: update_graph(tree,int(inp1.get())))
bt1.place(relx=0.1, rely=0.3, relwidth=0.8, relheight=0.1)
bt2 = Button(Root, text="删除结点", command=lambda: update_graph_del(tree,int(inp2.get())))
bt2.place(relx=0.1, rely=0.5, relwidth=0.8, relheight=0.1)
bt3 = Button(Root, text="二叉树的层次遍历", command=lambda: visualize_level_order(G, pos))
bt3.place(relx=0.1, rely=0.6, relwidth=0.8, relheight=0.1)
# 运行Tkinter窗体
Root.mainloop() 
#保存
write_to_file(tree,file_path)

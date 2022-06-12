using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab6OPSharp
{
    public class Tree
    {
        public Tree(int value) // Утворення кореня дерева та задання йому значення за допомогою реалізованого конструктора
        {
            Root = new Node(value);
        }

        public Node Root { get; } //Корінь дерева


        public void Insert(int value) => InsertHelper(value, Root);


        private void InsertHelper(int value, Node root) //Додавання нової вершини у дерево згідно до правил упорядкованості у бінарному дереві
        {
            if (value < root.Value)
            {
                if (root.Left == null)
                    root.Left = new Node(value);
                else InsertHelper(value, root.Left);
            }
            else if (value > root.Value)
            {
                if (root.Right == null)
                    root.Right = new Node(value);
                else InsertHelper(value, root.Right);
            }
            
        }


        public string PreorderTraverse() => string.Join("\n", PreorderTraverseHelper(Root, new List<Node>()));



        private List<Node> PreorderTraverseHelper(Node node, List<Node> nodes) //Виведення дерева та його вершин без координат
        {
            nodes.Add(node);
            if (node.Left != null)
                PreorderTraverseHelper(node.Left, nodes);
            if (node.Right != null)
                PreorderTraverseHelper(node.Right, nodes);
            return nodes;
        }

        public int CountNodes()  //Підрахунок кількості вершин дерева
        {
            int count = 0;
            CountNodesHelper(ref count, Root);
            return count;
        }


        private void CountNodesHelper(ref int count, Node? node) //Підрахунок кількості за рахунок обходу вершин
        {
            if (node == null) return;
            count++;
            CountNodesHelper(ref count, node.Left);
            CountNodesHelper(ref count, node.Right);
        }



        public string PreorderTraverseWithCoordinates()  //Виведення вершин з координатами(рівень,гілка)
        {
            var nodes = PreorderTraverseHelper(Root, new List<Node>()); //Масив вершин отриманий з методу звичайного виведення
            StringBuilder res = new StringBuilder();
            foreach (Node node in nodes)
            {
                int depth = 0, branch = 0;
                GetNodesCoordinate(ref depth, ref branch, node, Root);
                res.Append($"({node}, ({depth}, {branch}))\n");
            }

            return res.ToString();
        }







        private void GetNodesCoordinate(ref int depth, ref int branch, Node nodeToFind, Node? root) //Отримання координат вершини
        {
            if (root == null || root.Value == nodeToFind.Value) return;
            depth++;
            if (nodeToFind.Value < root.Value)
            {
                GetNodesCoordinate(ref depth, ref branch, nodeToFind, root.Left);
            }
            else
            {
                branch++;
                GetNodesCoordinate(ref depth, ref branch, nodeToFind, root.Right);
            }
        }


    }
}

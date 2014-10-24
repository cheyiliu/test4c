为了显示linux对signal的处理流程，我们需要进行两个步骤。第一，输入gcc sig.c -o sig, 然后输入./sig即可；第二则重启一个console窗口，输入ps -aux | grep sig， 在获取sig的pid之后然后输入kill -INT 2082， 我们即可得到如下的输出。

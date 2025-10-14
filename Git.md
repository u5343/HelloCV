<h2 id="wQP3V">配置</h2>
我的用户名为u5343，邮箱为abanli12138@outlook.com。

![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760011822937-c1f2eeb2-e220-4b0d-8d99-17c47094f3d3.png)

<h2 id="sMlUp">版本库</h2>
<h5 id="Kd9Rg">练习</h5>
首先在用户(我)的主目录下创建一个新的文件夹。

`mkdir ~/git`

![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760157456195-5d614234-f1fb-4554-b12a-3f92449dd90f.png)

~~哇哦，看不懂呢。~~

提示建议重命名一下，于是照做了。

`git branch -m main`

<h5 id="t7QJY">添加文件</h5>
向git仓库中添加文件分为两步：先用`add`把文件添加到仓库里，然后用`commit`表示提交并附上说明。

根据教程，向仓库中添加一个readme.txt。

![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760158049444-4210b85b-fa48-4481-bc38-17ddcca6a0b7.png)

成功了。

<h5 id="B1erS">检查状态</h5>
`status`命令可以检查文件是否被修改过。如下图。

![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760158240036-6aa61490-6290-4b5c-a699-35e5bb0a8295.png)

第一个`status`返回的是完全不作修改的结果，第二个status返回了文件在工作区被修改后的结果。



`diff`命令用于查看修改结果。

![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760158412734-6f46182d-a328-4202-a5fc-c5c8b9926652.png)



<h5 id="t539s">版本回退</h5>
`log`命令可以查看日志。

![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760158502510-ac48cf12-f3d0-42d4-b1ba-1131e296257a.png)

<h6 id="Cb7No">`reset`命令：</h6>
`<font style="color:rgb(75, 85, 99);background-color:rgb(229, 231, 235);">--hard</font>`<font style="color:rgb(31, 41, 55);background-color:rgb(249, 250, 251);">会回退到上个版本的已提交状态；</font>

<font style="color:rgb(31, 41, 55);background-color:rgb(249, 250, 251);"></font>`<font style="color:rgb(75, 85, 99);background-color:rgb(229, 231, 235);">--soft</font>`<font style="color:rgb(31, 41, 55);background-color:rgb(249, 250, 251);">会回退到上个版本的未提交状态；</font>

`<font style="color:rgb(75, 85, 99);background-color:rgb(229, 231, 235);">--mixed</font>`<font style="color:rgb(31, 41, 55);background-color:rgb(249, 250, 251);">会回退到上个版本已添加但未提交的状态。</font>

`<font style="color:rgb(31, 41, 55);background-color:rgb(249, 250, 251);">HEAD</font>`<font style="color:rgb(31, 41, 55);background-color:rgb(249, 250, 251);">表示当前版本，</font>`<font style="color:rgb(31, 41, 55);background-color:rgb(249, 250, 251);">HEAD^</font>`<font style="color:rgb(31, 41, 55);background-color:rgb(249, 250, 251);">表示上一个版本，</font>`<font style="color:rgb(31, 41, 55);background-color:rgb(249, 250, 251);">HEAD~100</font>`<font style="color:rgb(31, 41, 55);background-color:rgb(249, 250, 251);">表示往前回溯一百个版本。</font>

![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760158704874-8d9b7cc2-a746-47fc-a3ad-5dd32ca82bd7.png)

如上图，可见回退版本之后日志上已经没有新版本的信息了。

如果想要“回到未来”，用`reflog`命令。  
	![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760158854111-4deacc61-3cfa-4899-868e-e5035b4dd83b.png)

`reflog`命令显示了对仓库执行的命令，所以回退之后，原来的新版本并不会真的消失。

<h2 id="GyAQ0">工作区与暂存区</h2>
![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760159167710-92c9a0a8-db29-4870-ad28-fc9c461a6f2c.png)

平时隐藏的`.git`文件夹是版本库。

![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760159242266-76ca20b6-5459-4c95-92ee-c9794a0f4bb4.png)

上图中，`stage`代表的就是暂存区。工作区的文件通过`add`添加到暂存区，再经由`commit`一次性全部提交至仓库。

<h5 id="NHGh8">管理修改</h5>
依据上图的工作原理，git管理并追踪的是**修改而非文件本身**。

也就是说，单纯修改文件并不会被git记录，只有当把文件用`add`添加至暂存区后，才算完成了一次修改。

<h5 id="l84qy">撤销修改</h5>
撤销修改分为三种：撤销尚未被添加到暂存区的修改、撤销已经被添加到暂存区的修改，以及撤销提交至本地仓库中的修改。

1.`checkout -- <file>`可以撤销工作区中发生的所有修改，将工作区中的内容还原为其上一次被`add`或者`commit`时的内容。

`checkout`命令的本质是用版本库里的版本替换掉工作区内的版本。

![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760235062792-3d439ae5-907b-435f-ae32-4a4158bdcedb.png)

如上图，工作区中的readme.txt被还原了。

经过测试，`restore <file>`也可以做到同样的事情。



2.`reset HEAD <file>`可以将暂存区的修改回退到工作区，也就是说，适用于错误的修改已经被`add`到暂存区，但还没有`commit`到仓库的情况。

![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760235244985-86e15893-aace-4fb4-9a1a-d867acfa587f.png)

如图，经过`reset`，已经被`add`到暂存区的修改回退到了工作区，也就是回到了第一种情况。

经过测试，`restore --staged <file>`可以做到相同的事情。



3.如果要撤销提交至本地仓库中的修改，采用版本回退。

<h5 id="NZG5p">删除和复原文件</h5>
上文提到，`checkout`的本质是用版本库中的文件替换工作区内的文件。

下面演示从`checkout`复原在工作区中被删除的文件。![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760235533676-cbde88fc-16d0-42a8-bb69-00b33489eb03.png)

我们先提交一个文件。如上图。

![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760235564381-1bdf80e6-47e1-4a80-9e91-1bc0ddd5c9e0.png)

然后把它从工作区里删除。![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760235596425-a9fb8e61-f4f5-4271-a414-18fdebf044e0.png)

使用`status`检查之后，git提示工作区中的`readme.txt`被删除了。

![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760235661860-3ec3a6ef-14fd-4a1a-a324-83f9d20216cc.png)

使用`checkout`之后，文件被复原到了工作区。

如果想在版本库中删除文件，使用git下的`rm`命令。

![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760235865103-528dc154-75dc-499b-945f-1aeef88fbe39.png)

如上图。不要忘记在版本库中删除文件后要`commit`上去。

<h2 id="P30FT">远程仓库</h2>
首先用`ssh-keygen`创建了属于我的邮箱的ssh公钥和密钥，然后上传到了github。

然后将本地的仓库和我的HelloCV关联起来。![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760273945731-d2102d1b-78b7-44bb-985b-b16879a1bca6.png)

当我试着克隆的时候：![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760274204396-652f0ec1-0807-4b46-a35b-5a2b7dea4067.png)

看来有点问题呢。解决问题的文档见[另一篇笔记](https://www.yuque.com/qiegao-hhxaz/vv3dvo/kka3r7m20edggcry/edit)。

<h5 id="Q3NBJ">推送与克隆</h5>
实际上就是把修改发送到github，以及从github下载修改到本地。

![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760276502984-42013749-3c37-49e7-9355-cf3e8bb549e5.png)

先克隆一下。![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760276540314-ccdc7721-ccdd-4f1c-bd93-674b5e336865.png)	原来的`/git`文件夹下面多了一个`/HelloCV`文件夹。里面的内容和github上面是一样的。

<h2 id="wmYNg">分支</h2>
git的分支使用了非常精巧的指针。分支的原理不再赘述。

<h5 id="vrlt2">创建与合并</h5>
`checkout -b <name>`表示创建并切换分支，相当于`branch <name>`和`checkout <name>`。

`switch -c <name>`和`switch <name>`可以做到相同的事情。

`branch`命令可以查看当前分支。![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760317259882-2d90a325-fb51-45e8-942d-17104946d1e8.png)

接下来在dev分支下修改`README.md`。

![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760317284959-1ed95ae8-b8be-4146-b463-9892a6737ea0.png)

README被我修改为空白。这一修改被提交至dev分支。

接下来回到main分支。

![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760317338623-6d5299c8-504d-442b-974e-bc8c97375d5e.png)

可见main分支下的文件没有变化。真神奇。

接下来合并分支，合并用的命令是`merge`。

`merge <name>`，合并某分支到当前分支。

合并会默认开启fast forward模式，使用参数`--no-ff`来禁用。

禁用fast forward会保留合并的历史。就是说，`merge <name>`让人看不出来合并过，而`merge --no-ff`让人可以看到合并的历史。![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760317496399-470fcf08-c77a-4cbe-9d06-f88686c0d03f.png)

然后就可以删除dev分支了。`branch -d <name>`可以删除分支。

<h5 id="Zdx33">解决冲突</h5>
首先创建一个新的分支并且修改一点东西。![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760317876499-7588e02e-6a1c-40d8-a6c4-8b7cba8c19ec.png)

然后切换回main分支。![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760317891126-cf2c0d07-2998-45cb-aebf-6f58c700597c.png)

这次弹出的提示和上次不一样呢。提示说我的分支比github里的main分支多了一次提交——也就是刚才在“创建与合并”一节中，合并分支导致`README.md`中的内容变成了空白。使用`push`可以把本地的修改推送给github。我们先不管这个。

![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760318559911-80fa913f-76b9-42e5-bdf3-575a0e1b3818.png)

main分支和dev分支的`README.md`不一样，所以发生了冲突。

除发生冲突的文件以外，分支的其余部分都已经合并了。

![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760318641018-7854861a-25e0-447b-bffd-9cc4c2006fe4.png)

这个时候再查看这个文件，git会标识出冲突的地方。![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760318696199-b2c55ffa-e9ec-44b5-81da-afbf49fc539c.png)

把冲突的地方改掉就可以正常提交了。![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760318867259-3786b9ea-da6b-4cb1-8919-3816a6828777.png)

不要忘记先`add`再提交。因为`merge`之后两个分支的其余部分都合并完成了，只需要对发生冲突的文件进行一次修改就可以了。

<h5 id="jkJtK">stash命令</h5>
`stash`可以储存分支的工作现场。

`stash list`可以查看stash的记录。

`stash apply`和`stash pop`可以恢复先前储存的工作现场。区别为后者会删除stash记录。

![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760348551608-8f218e84-a4f8-44ed-9023-ed6737f4e1a6.png)

可见恢复之后自动执行了一次`status`，恢复到了文件尚未被`add`的状态。

<h5 id="eLOlO">cherry-pick命令</h5>
用途是复制某次提交到指定的分支。![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760348855468-8dd40630-7fce-4af5-bc02-de7ef4e58b92.png)

好像有点问题。原来是main分支和dev分支分别`commit`了不同的内容，在合并过程中有了冲突。用解决冲突的方法就可以解决了。

<h5 id="T3LEp">与远程仓库</h5>
`remote`可以查看远程库的信息，参数`-v`可以显示更详细的信息。

`push`命令可以把版本库的内容推送给远程库。![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760406980362-001fc70c-0286-475d-8942-6b33cea7b7fd.png)

又出问题了，这次说有另一个人先对我的远程库推送了内容。哦想起来了，我的确在github网页端对远程库改动了一点东西。

总之这种时候需要先把最新的提交抓下来。

`pull`命令可以从远程库抓取最新的一次提交。![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760407142797-1ab323a3-65db-4d31-a365-a8f31beb6d6a.png)

又给了好多hint哦。

我在网页端对远程库的改动是删除了`README.md`文件。这里提示的意思是本地库与远程库分别由不同的提交，git想知道该采用什么方式协调它们。

我选择直接merge，也就是执行`git pull --no-rebase`。![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760407761583-20473b3a-47d4-4482-876c-8d64695593f5.png)

然后就又回到解决冲突的步骤了。

![](https://cdn.nlark.com/yuque/0/2025/png/61472747/1760407796071-c35d80fa-f3be-4766-b5f1-1394c21e8690.png)

<h6 id="mhIVR">rebase</h6>
`rebase`命令会将本地提交重新放置在远程提交之后，使改动历史变得更加线性而整洁。

~~这个原理有点复杂以后再详细了解。~~






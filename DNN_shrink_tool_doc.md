####  DNN-shrink-tool manual



* description 

> DNN shrink tool is a tool  which takes your baseline neural network model as  input  and outputs  the shrank model.  baseline model(model before shrink)  defined  in pytorch is supported ,  output can be pytorch model or onnx model. 
>
>dependency:
>
>**torch version >=1.0 (may be a lower version also works)**
>
>**tensorboard**
>
>**graphviz(if using visualize_package)**







* restriction to be confirmed 

> As  default shrink algorithm of this tool is [Morphnet](https://arxiv.org/abs/1711.06798) , not all baseline network is supported.Also, implement of generator also has some restrictions. Baseline model to be shrank should has the following features
>
> 1. batch normalization layer is necessary.  and also only the convolution, bacthnorm layer pair will be the shrink target. this is due to morphnet's implement details. if no batchnormalization layers exist in your model, this tool will not work.
>
> 2. currently , network generator(parts of this tool)  can generate network which  contains the following dataflow depth-change layer or operation ( takes input data and has the ability to change its depth **e.g. a conv layer takes an input of shape(3,224,224) and change it to (32,112,112) the depth changed from 3 to 224**
>
>    
>
>    ***linear layer***
>
>    ***conv layer*** 
>
>    ***view operation***
>
>    ***padding operation***
>
>    
>
>    if other depth-change operations  exist in your baseline, the generator may not work correctly 
>
>    





* preparation:

> since this tool is not an end-to-end tool, before shrinking your neural network models, some work needed to be done by yourself 
>
> **environment of training baseline model **
>
>   dataset used to train and test is necessary 
>
>   training code is also needed ,as in the shrink-process , training of  baseline  will be done
>
>   of course, if your want to test shrank model's performance , test code is also needed
>
> **your own python file**
>
> in shrink_package, **necessary_function.py**  is just used for demo, when shrink  network for your own task,  this file should be reorganized.
>
> the following 3 functions is needed:(take a reference of necessary_function.py for demo,it will be easy to make it if your has training and test code )
>
> *  train_one_epoch(model,lr)
>
>   this function takes your model and learning rate as input and train your model for one epoch . sgd optimizer is recommended ,and in most cases the learning rate should be setted as 0.1 or 0.01
>
> * train(model)
>
>   which takes your model as input and train it as your original train process(including the setting of scheduler,optimizer,etc )
>
> * test(model)
>
>    test your model . pay attention, make this function return a larger-better evaluation value like accuracy.
>
>   e.g if your original test function return a loss, your should return 1/loss
>
> note, in  tool network is be setted to train on cuda in default. 
>
> 
>
> **some changes for your baseline network defining code**(for certain options and task)
>
> * add **generate_graph** attribution for baseline in your baseline network define files
>
>     for certain task,some networks may return a list or dictionary as an output instead of tensors .although the list can be used,  add a **generate_graph**   attribution to your baseline, and when it is setted as True, make sure your network return a tensor 
>
>   e.g. in your baseline network 's  define file, if your original return is a dictionary{'output1':output1,'output2':output2 }
>
>   >
>   >
>   >def __ init __(self,....):
>   >
>   >​    self.generate_graph = False
>   >
>   >
>   >
>   >def forward(self,x):
>   >
>   >###  your forward process
>   >
>   >​    if self.generate_graph :
>   >
>   >​       return output['output1']
>   >
>   >​    else:
>   >
>   >​      return output         
>   >
>   >
>
>   ​    if your original output is a list,  can set the output be tuple(output) simply . if your original output is a tensor, nothing needed to be done
>
> * add **back_bone_only** attribution for baseline in your baseline network define files
>
>    some task's network has a backbone parts and  other parts ,like upsampling or heatmappig 
>
>    if you only want to shrink the backbone parts of your network,set a back_bone_only attribution for baseline ,and make sure if this option is setted , output of backbone parts (a tensor) will be return
>
>   e.g.
>
>   > def forward(self,x):
>   >
>   >   
>   >
>   > y = backbone(x)## backbone ,your backbone parts network
>   >
>   > if self.back_bone_only:
>   >
>   > ​    return y
>   >
>   > else:
>   >
>   >    return your original output
>
>     

* main use case of dnn shrink tool:

>to be updated
>
>










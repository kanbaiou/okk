﻿using UnityEngine;
using System.Collections;
using System.Collections.Generic;

/// <summary>
/// 资源管理类
/// </summary>
public class ResourceManager
{
    private static Dictionary<int,Sprite> spriteDIC;

    //类被加载时执行1次
    static ResourceManager()
    {
        //根据？名字    查找？图片
        //键值对集合  /  字典集合
        spriteDIC = new Dictionary<int, Sprite>();
        Sprite[] spriteArray = Resources.LoadAll<Sprite>("2048Atlas");
        //将数组元素存储到字典集合中
        foreach (var item in spriteArray)
        {
            int intName = int.Parse(item.name);
            spriteDIC.Add(intName, item);
        }
    }

    public static Sprite GetImage(int number)
    {
        return spriteDIC[number];
    }
 
}

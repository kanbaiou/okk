using UnityEngine;
using System.Collections;
using UnityEngine.UI;
using Console2048;
using UnityEngine.EventSystems;
using MoveDirection = Console2048.MoveDirection;

/// <summary>
/// 
/// </summary>
public class GameController : MonoBehaviour,IPointerDownHandler,IDragHandler
{
    private GameCore core;
    private NumberSprite[,] spriteActionArray;

    //一、创建方格
    private void Start()
    { 
        core = new GameCore();
        spriteActionArray = new NumberSprite[4, 4];

        Init();
        GenerateNumber();
        GenerateNumber();
    } 

    private void Init()
    {
        for (int r = 0; r < 4; r++)
        {
            for (int c = 0; c < 4; c++)
            {
                spriteActionArray[r, c] = CreateSprite(r, c);
            }
        }
    } 

    private NumberSprite CreateSprite(int r,int c)
    {
        GameObject go = new GameObject(r.ToString() + c.ToString());
        go.AddComponent<Image>();
        go.transform.SetParent(transform,false);
        var script = go.AddComponent<NumberSprite>();//执行Awake方法，Start会在"下一帧"才执行
        script.SetImage(0);
        return script;
    }

    //二、生成新数字
    private void GenerateNumber()
    { 
        Location loc;
        int number;
        core.GenerateNumber(out loc, out number);
        //?修改loc位置上的精灵
        //transform.Find(loc.RIndex.ToString()+loc.CIndex.ToString())
        spriteActionArray[loc.RIndex, loc.CIndex].SetImage(number);
        //播放生成动画
        spriteActionArray[loc.RIndex, loc.CIndex].CreateEffect();
    }
      
    //四、输入检测 
    private Vector2 beginPoint;
    private bool isDown = false;//是否按下
    public void OnPointerDown(PointerEventData eventData)
    {
        beginPoint = eventData.position;
        isDown = true;
    }
    //拖拽时每帧执行
    public void OnDrag(PointerEventData eventData)
    {
        if (!isDown) return;

        Vector3 touchOffset = eventData.position - beginPoint;
        float x = Mathf.Abs(touchOffset.x);
        float y = Mathf.Abs(touchOffset.y);

        //int? a=null; 可空值类型
        MoveDirection? dir = null;
        if (x > y && x >50)
        {
            dir = touchOffset.x > 0 ? MoveDirection.Right : MoveDirection.Left;
        }
        if (y > x && y >50)
        {
            dir = touchOffset.y > 0 ? MoveDirection.Up : MoveDirection.Down;
        }

        if (dir != null)
        { 
            core.Move(dir.Value);//获取可空值类型中的值类型数据
            isDown = false;
        } 
    }

    //三、更新界面
    private void Update()
    {
        if (core.IsChange)
        {
            //更新界面
            UpdateMap();
            GenerateNumber();
            if (core.IsOver())
            {

            }
            core.IsChange = false;
        }
    }

    private void UpdateMap()
    {
        for (int r = 0; r < 4; r++)
        {
            for (int c = 0; c < 4; c++)
            {
                spriteActionArray[r, c].SetImage(core.Map[r, c]);
            }
        }
    }
}

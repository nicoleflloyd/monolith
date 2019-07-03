var imgArray = new Array();

imgArray[0] = new Image();
imgArray[0].src = 'assets/joy/images/trans-titles/1.jpg';

imgArray[1] = new Image();
imgArray[1].src = 'assets/joy/images/trans-titles/2.jpg';

imgArray[2] = new Image();
imgArray[2].src = 'assets/joy/images/trans-titles/3.jpg';

imgArray[3] = new Image();
imgArray[3].src = 'assets/joy/images/trans-titles/4.jpg';

imgArray[4] = new Image();
imgArray[4].src = 'assets/joy/images/trans-titles/5.jpg';

imgArray[5] = new Image();
imgArray[5].src = 'assets/joy/images/trans-titles/6.jpg';

imgArray[6] = new Image();
imgArray[6].src = 'assets/joy/images/trans-titles/7.jpg';

imgArray[7] = new Image();
imgArray[7].src = 'assets/joy/images/trans-titles/8.gif';

imgArray[8] = new Image();
imgArray[8].src = 'assets/joy/images/trans-titles/9.jpg';

imgArray[9] = new Image();
imgArray[9].src = 'assets/joy/images/trans-titles/10.jpg';

imgArray[10] = new Image();
imgArray[10].src = 'assets/joy/images/trans-titles/11.jpg';

imgArray[11] = new Image();
imgArray[11].src = 'assets/joy/images/trans-titles/12.jpg';

imgArray[12] = new Image();
imgArray[12].src = 'assets/joy/images/trans-titles/13.jpg';

imgArray[13] = new Image();
imgArray[13].src = 'assets/joy/images/trans-titles/14.jpg';

imgArray[14] = new Image();
imgArray[14].src = 'assets/joy/images/trans-titles/15.jpg';


/*------------------------------------*/

function nextImage(element)
{
    var img = document.getElementById(imageIcon);

    for(var i = 0;i<imgArray.length; i++)
    {
        if(imgArray[i] == img)
        {
            if(i == imgArray.length)
            {
                var j = 0;
                document.getElementById(imageIcon).src = imgArray[j].src;
                break;
            }
            else
            var j = i + 1;
            document.getElementById(imageIcon).src = imgArray[j].src;
            break;
        }
    }   
}

const arr = [4, 3, 5, 6, 1, 6, 8, 1, 9, 1];


function getFreq(arr)
{
    freqMap = [];
    for(let i=0; i<arr.length; i++)
    {
        let currKey = arr[i];
        let curValue=0;
        for(let j = i+1; j<arr.length; j++)
        {
            let curValue=0;
            if(arr[j] === currKey)
                curValue = curValue + 1;
        }
        console.log(currKey)
        console.log(curValue)
        freqMap.push({currKey : curValue});

    }
    
}

getFreq(arr);
// Tic Tac Toe game written by Nikola Ristovski
// 24.4.'25.

let gameOn = false;
let playerTurn = 1;
let matrixValues = [0,0,0,0,0,0,0,0,0];

var beginButton = Array.from(document.getElementsByClassName("begin-game"))[0];

function beginButtonClick()
{
    gameOn = true;
    beginButton.style.display = "none";
    var playerTurnDisplay = Array.from(document.getElementsByClassName("player-turn"))[0];
    console.log(playerTurnDisplay);
    playerTurnDisplay.style.display = "flex";
    console.log("The game has begun!");
    let board = Array.from(document.getElementsByClassName("board"))[0];
    board.style.transition = "ease-in-out 0.4s";
    board.style.transform = "rotate(360deg)";
    setTimeout(()=>{
        board.style.transition = "none";
    }, 400);
}

beginButton.addEventListener("click", beginButtonClick);

let cellArray = Array.from(document.getElementsByClassName("board-cell"));

cellArray.forEach(cell => {
    cell.addEventListener("click", function() {

        if(!gameOn)
            return;
        else
        {
            let row = cell.getAttribute("data-row");
            let col = cell.getAttribute("data-col");

            //In case player picks the cell already picked before

            if(matrixValues[parseInt(row)*3 + parseInt(col)] != 0)
            {
                console.log(`Player ${playerTurn} tried noting cell [${row},${col}] which is already marked by player ${matrixValues[parseInt(row)*3 + parseInt(col)]}.`);
                cell.style.animation = "none";
                cell.offsetHeight;
                cell.style.animation =  "wiggle 0.2s ease-in-out";
                return;
            }

            matrixValues[parseInt(row)*3 + parseInt(col)] = playerTurn;
            console.log(`Player ${playerTurn} noted cell [${row},${col}].`);
            let playerTurnNumber = Array.from(document.getElementsByClassName("player-number"))[0];
            
            if(playerTurn == 1)
            {
                cell.textContent = 'X';
                cell.style.color = "blue"
                cell.style.animation = "none";
                cell.offsetHeight;
                cell.style.animation = "zoom 0.5s"
            }
            else
            {
                cell.textContent = "O";
                cell.style.color = "red";
                cell.style.animation = "none";
                cell.offsetHeight;
                cell.style.animation = "zoom 0.5s"
            }

            setTimeout(() => {
                    if(checkWinCondition(row, col))
                    {
                        gameOn = false;
                        let winner = playerTurn%2+1;
                        console.log(`Game finished! Player ${winner} has won!`);
                        //alert(`Game finished! Player ${winner} has won!`);
                        gameEndInfo(`Game finished! Player ${winner} has won!`);
                    }
                    else if(checkTieCondition())
                    {
                        gameOn = false;
                        console.log("Game is finished! It's a tie!");
                        //alert("Game is finished! It's a tie!");
                        gameEndInfo("Game is finished! It's a tie!");
                    }
                    else
                        console.log(`Game is still in play!`);
                }, 50
            )

            playerTurn = playerTurn%2+1;
            playerTurnNumber.textContent = playerTurn + "'s";

            if(playerTurn == 1)
            {
                playerTurnNumber.style.color = "blue";
                playerTurnNumber.style.animation = "none";
                playerTurnNumber.offsetHeight;
                playerTurnNumber.style.animation = "zoom 0.5s"
            }
            else
            {
                playerTurnNumber.style.color = "red";
                playerTurnNumber.style.animation = "none";
                playerTurnNumber.offsetHeight;
                playerTurnNumber.style.animation = "zoom 0.5s"
            }
        }
    });
})

function gameEndInfo(text)
{
    let gameEndInfoDiv = document.querySelector(".game-end-info");
    gameEndInfoDiv.style.display = "flex";
    let gameEndInfoText = gameEndInfoDiv.querySelector("h1");
    gameEndInfoText.textContent = text;
    gameEndInfoDiv.style.animation = "expand 0.25s";
    document.body.classList.add(".blur");
    setTimeout(() => {
        gameEndInfoDiv.style.animation = "none";
        gameEndInfoDiv.offsetHeight;
        gameEndInfoDiv.style.animation = "collapse 0.25s";
        setTimeout(() => {
            gameEndInfoDiv.style.display = "none";            
        }, 255);
    }, 3000);
}

function checkTieCondition()
{
    let product = matrixValues.reduce(
        (acc, cur) => {
            return acc * cur;``
        }
    , 1);
    console.log("Product is " + product);
    if(product != 0)
        return true;
    return false;
}

function checkWinCondition(row, col)
{
    console.log(`Checking win condition for [${row},${col}]`)
    if(row == 0 && col == 0) //0 0
    {
        if
        (
            (
                (matrixValues[0] === matrixValues[1]) && (matrixValues[0] === matrixValues[2])
            ) 
            ||
            (
                (matrixValues[0] === matrixValues[3]) && (matrixValues[0] === matrixValues[6])
            )
            ||
            (
                (matrixValues[0] === matrixValues[4]) && (matrixValues[0] === matrixValues[8])
            )
        )
        {
            return true;
        }
    }
    else if(row == 1 && col == 0) //1 0
    {
        if
        (
            (
                (matrixValues[3] === matrixValues[4]) && (matrixValues[3] === matrixValues[5])
            ) 
            ||
            (
                (matrixValues[3] === matrixValues[0]) && (matrixValues[3] === matrixValues[6])
            )
        )
        {
            return true;
        }
    }
    else if(row == 2 && col == 0) //2 0
    {
        if
        (
            (
                (matrixValues[6] === matrixValues[7]) && (matrixValues[6] === matrixValues[8])
            ) 
            ||
            (
                (matrixValues[6] === matrixValues[3]) && (matrixValues[6] === matrixValues[0])
            )||
            (
                (matrixValues[6] === matrixValues[4]) && (matrixValues[6] === matrixValues[2])
            )
        )
        {
            return true;
        }
    }
    else if(row == 0 && col == 1) //0 1
    {
        if
        (
            (
                (matrixValues[1] === matrixValues[0]) && (matrixValues[1] === matrixValues[2])
            ) 
            ||
            (
                (matrixValues[1] === matrixValues[4]) && (matrixValues[1] === matrixValues[7])
            )
        )
        {
            return true;
        }
    }
    else if(row == 1 && col == 1) // 1 1
    {
        if
        (
            (
                (matrixValues[4] === matrixValues[3]) && (matrixValues[4] === matrixValues[5])
            ) 
            ||
            (
                (matrixValues[4] === matrixValues[1]) && (matrixValues[4] === matrixValues[7])
            )
            ||
            (
                (matrixValues[4] === matrixValues[0]) && (matrixValues[4] === matrixValues[8])
            ) 
            ||
            (
                (matrixValues[4] === matrixValues[2]) && (matrixValues[4] === matrixValues[6])
            )
        )
        {
            return true;
        }
    }
    else if(row == 2 && col == 1) // 2 1
    {
        if
        (
            (
                (matrixValues[7] === matrixValues[6]) && (matrixValues[7] === matrixValues[8])
            ) 
            ||
            (
                (matrixValues[7] === matrixValues[4]) && (matrixValues[7] === matrixValues[1])
            )
        )
        {
            return true;
        }
    }
    else if(row == 0 && col == 2) //0 2
    {
        if
        (
            (
                (matrixValues[2] === matrixValues[0]) && (matrixValues[2] === matrixValues[1])
            ) 
            ||
            (
                (matrixValues[2] === matrixValues[5]) && (matrixValues[2] === matrixValues[8])
            )
            ||
            (
                (matrixValues[2] === matrixValues[4]) && (matrixValues[2] === matrixValues[6])
            )
        )
        {
            return true;
        }
    }
    else if(row == 1 && col == 2) //1 2
    {
        if
        (
            (
                (matrixValues[5] === matrixValues[4]) && (matrixValues[5] === matrixValues[3])
            ) 
            ||
            (
                (matrixValues[5] === matrixValues[2]) && (matrixValues[5] === matrixValues[8])
            )
        )
        {
            return true;
        }
    }
    else if(row == 2 && col == 2) //2 2
    {
        if
        (
            (
                (matrixValues[8] === matrixValues[7]) && (matrixValues[8] === matrixValues[6])
            ) 
            ||
            (
                (matrixValues[8] === matrixValues[5]) && (matrixValues[8] === matrixValues[2])
            )
            ||
            (
                (matrixValues[8] === matrixValues[4]) && (matrixValues[8] === matrixValues[0])
            )
        )
        {
            return true;
        }
    }
    else
        return false;

}

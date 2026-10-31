let inputEl = document.querySelector("#area");
let btn = document.querySelector("button");
let pEl = document.querySelector("#demo");

btn.addEventListener("click", (event) =>{
    if(inputEl.value != ""){
        pEl.textContent = `Добре дошъл, ${inputEl.value}!`;
        pEl.className = "green";
    } else {
        pEl.textContent = "Nothing has been typed!"
        pEl.className = "black";
    }
})
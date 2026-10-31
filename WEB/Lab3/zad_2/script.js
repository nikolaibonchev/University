let arr = ["osp", "c#", "web", "pp", "pmp"];

let list = document.getElementById("list");

for (const element of arr){
    let newListElement = document.createElement("li");
    newListElement.textContent = element;
    list.appendChild(newListElement);
}
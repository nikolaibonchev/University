document.addEventListener("click", (e)=>{
    console.log(e.target);
    if(e.target.tagName == "IMG" && e.target.id == "hide") {
        e.target.className = "dis"
    };

    if(e.target.tagName == "IMG" && e.target.id == "big"){
        e.target.className = "bigger"
    }
})
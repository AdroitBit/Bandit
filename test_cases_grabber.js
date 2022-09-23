var is_last_child = function(node) {
    return node.parentNode.lastElementChild == node;
};

eles=document.querySelectorAll("p.ndfHFb-c4YZDc-cYSp0e-DARUcf-Df1ZY-eEGnhe")
eles=[].slice.call(eles)
found_example=false
eles.filter(function(e,i,a){
    if(e.innerText.includes("ตัวอย่าง")){
        found_example=true
        return false
    }
    if(found_example==false){
        return false
    }
    return true
    /*
    if(e.style.left=="9.41176%" && e.style.height=="1.07015%"){
        return true
    }
    return false
    */
})
eles=eles.map(function(e,i,a){
    return e.innerText
})
console.log(eles)

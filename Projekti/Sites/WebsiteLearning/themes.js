let theme = "light";

let themeButton = document.querySelector(".theme-button");
themeButton.addEventListener("click", () => {
    document.body.classList.toggle("dark-theme");
    if(theme == "light")
    {
        themeButton.textContent = "DARK THEME";
        theme = "dark";
    }
    else
    {
        themeButton.textContent = "LIGHT THEME";
        theme = "light";
    }
})
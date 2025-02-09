const sideMenu = document.querySelector("aside");
const menuBtn = document.querySelector("#menu-btn");
const closeBtn = document.querySelector("#close-btn");
const themeToggler = document.querySelector(".theme-toggler");

menuBtn.addEventListener("click", () => {
  sideMenu.style.display = "block";
});

closeBtn.addEventListener("click", () => {
  sideMenu.style.display = "none";
});

themeToggler.addEventListener("click", () => {
  document.body.classList.toggle("dark-theme-variables");

  themeToggler.querySelector("span:nth-child(1)").classList.toggle("active");
  themeToggler.querySelector("span:nth-child(2)").classList.toggle("active");
});

// Ensure Orders array is defined
const Orders = [
  { productName: "Laptop", productNumber: "12345", paymentStatus: "Paid", shipping: "Delivered" },
  { productName: "Headphones", productNumber: "67890", paymentStatus: "Pending", shipping: "Pending" },
  { productName: "Keyboard", productNumber: "54321", paymentStatus: "Paid", shipping: "Declined" },
];

Orders.forEach((orders) => {
  const tr = document.createElement("tr");
  const trContent = `
      <td>${orders.productName}</td>
      <td>${orders.productNumber}</td>
      <td>${orders.paymentStatus}</td>
      <td class="${
        orders.shipping === "Declined"
          ? "danger"
          : orders.shipping === "Pending"
          ? "warning"
          : "primary"
      }">${orders.shipping}</td>
      <td class="primary">Details</td>
  `;
  tr.innerHTML = trContent;
  document.querySelector("table tbody").appendChild(tr);
});

// Break Reminder Function with Snooze Option
function breakReminder() {
  let userChoice = confirm("Time for a break! Stretch and relax. 😊 \nClick OK to stop reminders or Cancel to snooze.");
  
  if (!userChoice) {
    setTimeout(breakReminder, 10000); // Snooze for 10 seconds
  }
}

// Start Break Reminder Every 20 Seconds
setInterval(breakReminder, 20000);

const MONTHS = [
  "January", "February", "March", "April",
  "May", "June", "July", "August",
  "September", "October", "November", "December",
];

function getDateSinceJan1(days) {
  // month is 0-indexed
  const d = new Date(2016, 0, days);
  return `${MONTHS[d.getMonth()]} ${d.getDate()}`;
}

function getResponse() {
  const before = document.getElementById("before");
  const bingo = document.getElementById("bingo");
  const after = document.getElementById("after");
  return new Promise((resolve, reject) => {
    const onBefore = () => {
      removeEventListeners();
      resolve(-1);
    };
    const onBingo = () => {
      removeEventListeners();
      resolve(0);
    };
    const onAfter = () => {
      removeEventListeners();
      resolve(1);
    };
    function removeEventListeners() {
      before.removeEventListener("click", onBefore);
      bingo.removeEventListener("click", onBingo);
      after.removeEventListener("click", onAfter);
    }
    before.addEventListener("click", onBefore);
    bingo.addEventListener("click", onBingo);
    after.addEventListener("click", onAfter);
  });
}

async function main() {
  let attempt = 1;
  // Total number of days = 366, from 1 to 366
  let left = 1;
  let right = 367;
  let mid = Math.floor(left + (right - left) / 2);
  let bday = getDateSinceJan1(mid);
  const h1 = document.getElementById("birthday");
  while (right - left > 1) {
    h1.innerHTML = `Attempt #${attempt}: Is your birthday ${bday}?`;
    const rc = await getResponse();
    if (rc === 0) {
      break;
    } else if (rc > 0) {
      left = mid + 1;
    } else {
      right = mid;
    }
    attempt++;
    mid = Math.floor(left + (right - left) / 2);
    bday = getDateSinceJan1(mid);
  }
  h1.innerHTML = `Your birthday is ${bday}! ` +
                 `It took ${attempt} attempt${attempt > 1 ? 's' : ''}.`;
  const before = document.getElementById("before");
  const bingo = document.getElementById("bingo");
  const after = document.getElementById("after");
  before.disabled = true;
  bingo.disabled = true;
  after.disabled = true;
}

main();

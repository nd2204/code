function is_valid_email(email) {
  const re = /^[\w-\.]+@([\w-]+\.)+[\w-]{2,4}$/
  return re.test(email)
    && email.length != 0
    && email != null
}

function is_valid_phonenum(num) {
  const re = /^[0-9]{8,12}$/
  return re.test(num)
}

document.addEventListener("DOMContentLoaded", () => {
  const form = document.querySelector('form')
  const email = document.getElementById('mail')
  const phone = document.getElementById('phone')

  var valid_email = false;
  var valid_phonenum = false;
  email.addEventListener("input", () => {
    valid_email = is_valid_email(email.value)
    if (!valid_email) {
      email.classList.add('invalid')
    } else {
      email.classList.remove('invalid')
    }
  })

  phone.addEventListener("input", () => {
    valid_phonenum = is_valid_phonenum(phone.value)
    if (!valid_phonenum) {
      phone.classList.add('invalid')
    } else {
      phone.classList.remove('invalid')
    }
  })

  form.addEventListener("submit", (event) => {
    const name = document.getElementById('name')
    const brief = document.getElementById('brief')
    const newsletter = document.getElementById('newsletter')

    var data = ""
    var nerr = 0;
    var error_log = ""

    if (name.value.length != 0) {
      data += "Ten: " + name.value + "\n";
    } else {
      nerr += 1;
      error_log += "Ten khong duoc de trong\n";
    }

    if (valid_phonenum) {
      data += "SDT: " + phone.value + "\n"
    } else {
      nerr += 1;
      error_log += "So dien thoai khong hop le\n";
    }

    if (valid_email) {
      data += "Email: " + email.value + "\n";
    } else {
      nerr += 1;
      error_log += "Email khong hop le\n";
    }

    if (nerr) {
      alert(error_log)
      event.preventDefault()
      return
    }

    data += "Project Brief: " + brief.value + "\n";
    data += "Subscribed to newsletters: " + newsletter.value + "\n";

    alert(data);
  })
})


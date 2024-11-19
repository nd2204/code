var mailingList = []

function push(array, elem) {
  let copy = array.slice();
  copy.push(elem);
  return copy;
}

function add_contact(mailingList, email) {
  return push(mailingList, email);
}

mailingList = add_contact(mailingList, "Hello");

console.log(mailingList);

function arraySet(array, idx, value) {
  let new_array = array.slice();
  new_array[idx] = value;
  return new_array;
}

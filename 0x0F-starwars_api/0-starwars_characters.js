#!/usr/bin/node
// Script that prints all characters from a Star Wars movie passed as argument
const request = require('request');
const { argv } = require('process');

const URL = `https://swapi-api.hbtn.io/api/films/${argv[2]}/`;

async function getCharacterName (url) {
  return new Promise((resolve) => {
    request(url, (_error, _response, body) => {
      resolve(JSON.parse(body).name);
    });
  });
}

async function printCharacters (_error, _response, body) {
  for (const url of JSON.parse(body).characters) {
    const name = await getCharacterName(url);
    console.log(name);
  }
}

request(URL, printCharacters);

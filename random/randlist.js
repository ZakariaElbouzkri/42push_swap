/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randlist.js                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 00:19:38 by zel-bouz          #+#    #+#             */
/*   Updated: 2022/12/20 06:08:29 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
  });
  
  readline.question('Enter range 0 - ? : ', (range) => {
    
    range = parseInt(range)
    let randlist = []
    for (i = 0; i < range; i++)
    {
      randlist.push(i)
    }
    
    randlist = randlist.sort((a, b) => 0.5 - Math.random());
    console.log(...randlist);

    readline.close();
});


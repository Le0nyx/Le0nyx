#!/bin/bash

filepath=$1
echo $filepath
echo "Has been written into $filepath" >> $filepath
# Append Christmas tree to the file

# Christmas Tree
# --------------
#       *
#      ***
#     *****
#    *******
#   *********
#  ***********
# *************
#       |

cat << "EOF" >> "$filepath"
                                  .
                     .       *
                           |         *
                .    *         .            *
                                       /
             *      .       ,    *          .    *
                            `;
                   *   -      ;:,   -    *     -   .
           .  -               ,:;:,
                  .          ,:;%;;:,           *
                       /    ::;%#%;::   *    .
                *           ::;%#%;:
                             `:%#%'  .   .,,.
                      *    .    #     .,sSSSSs
                                #  .,sSSSSSSSS
                             .,sSSSSSSSSSSSS'
                        .,sSSSSSSSSSSSSSSSSSs,
                    .sSSSSSSSSSSSSSSSSSSSSSSSS
                    sSSSSSSSSSSSSSSSSSSSSSSSS'
                    `SSSSSSSSSSSSSSSSSSSSSSS'
                    sSSSS;nww;SSS;mwwwn;SSSSs
                   `SSS;nnw;sSSSs;wwwnnn;SSSs
                 .sSS;nnnw;SSSSS;wwwnnn%;SSS
                  .SSSS;nnnww;SSS;mwwwnnn%;SS'
                  SSSSS;nnnwwwAstnerwwnnn%%;
                  `SSS'%nnnwwwmLeonwwwnnn%%;
                     ;%%nnnwwwmmmmmwwwnnn%%;
                     ;%%nnnwwwmmmmmwwwnnn%%;
                     ;%%nnnwwwmmmmmwwwnnn%%;
                     ;%%nnnwwwmmmmmwwwnnn%%;
                     ;%%nnnwwwmmmmmwwwnnn%%;
                     ;%%nnnwwwmmmmmwwwnnn%%;
                     ;%%nnnwwwmmmmmwwwnnn%%;
                     ;%%nnnwwwmmmmmwwwnnn%%;
                     ;%%nnnwwwmmmmmwwwnnn%%;
                     ;%%nnnwwwmmmmmwwwnnn%%;
                     ;%%nnnwwwmmmmmwwwnnn%%;
   ,                 ;%%nnnwwwmmmmmwwwnnn%%;
.,;;;,.,;            ;%%nnnwwwmmmmmwwwnnn%%;        ;     ;
  `;;;;,;;;,.,;      ;%%nnnwwwmmmmmnnnnnn%%;  ,    .;;,.,;;;.
   ;;;;;;;;,;;;;;,., ;%%nnnnnnnnn;,ooo,;n%%;   ;;;;;,;;,;;,;;;,.
   ;'   `;;;;;;,;;;;.;%%nnn;,ooo,;OOOOO;n%%;  .;;,;;;;;;;;;;,;;'',
         ;'  ';;;;,;;,...   OOOOO;`OOO'..,,;,;;,;;;''';;;''';;'
               ';;'    '''''`OOO'OOooo' ''' ;'   '     '
                '         ;,.,;, `OOO'
                      ;,.;;';;;';,;.
                  ;,.;;';;;;;;;;;;;'
                .,;;;;;;;;;;;;;;;'
                  ';'  ';'   ';;
                               `

EOF

echo "Christmas tree written to $filepath"

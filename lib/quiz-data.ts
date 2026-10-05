export type Question = {
  id: string
  prompt: string
  options: string[]
  answer: number
  explanation: string
}

export type Category = {
  id: string
  name: string
  description: string
  icon: 'globe' | 'flask' | 'landmark' | 'sparkles'
  questions: Question[]
}

export const SECONDS_PER_QUESTION = 20

export const categories: Category[] = [
  {
    id: 'general',
    name: 'General Knowledge',
    description: 'A little bit of everything to warm up your brain.',
    icon: 'sparkles',
    questions: [
      {
        id: 'g1',
        prompt: 'How many minutes are in a full day?',
        options: ['1,240', '1,440', '1,640', '2,400'],
        answer: 1,
        explanation: '24 hours × 60 minutes = 1,440 minutes.',
      },
      {
        id: 'g2',
        prompt: 'Which language has the most native speakers worldwide?',
        options: ['English', 'Spanish', 'Mandarin Chinese', 'Hindi'],
        answer: 2,
        explanation: 'Mandarin Chinese has over 900 million native speakers.',
      },
      {
        id: 'g3',
        prompt: 'What is the only food that never spoils if stored properly?',
        options: ['Rice', 'Honey', 'Salt crackers', 'Peanut butter'],
        answer: 1,
        explanation: 'Edible honey has been found in ancient Egyptian tombs.',
      },
      {
        id: 'g4',
        prompt: 'How many keys does a standard piano have?',
        options: ['76', '82', '88', '92'],
        answer: 2,
        explanation: 'A standard piano has 52 white keys and 36 black keys.',
      },
      {
        id: 'g5',
        prompt: 'Which planet is known for its prominent ring system?',
        options: ['Jupiter', 'Saturn', 'Neptune', 'Mars'],
        answer: 1,
        explanation: 'Saturn’s rings are made mostly of ice and rock particles.',
      },
      {
        id: 'g6',
        prompt: 'In which sport would you perform a “slam dunk”?',
        options: ['Volleyball', 'Tennis', 'Basketball', 'Rugby'],
        answer: 2,
        explanation: 'A slam dunk is when a player forces the ball through the hoop.',
      },
      {
        id: 'g7',
        prompt: 'What is the hardest natural substance on Earth?',
        options: ['Quartz', 'Granite', 'Diamond', 'Titanium'],
        answer: 2,
        explanation: 'Diamond scores 10, the maximum, on the Mohs hardness scale.',
      },
      {
        id: 'g8',
        prompt: 'How many sides does a hexagon have?',
        options: ['5', '6', '7', '8'],
        answer: 1,
        explanation: '“Hex” comes from the Greek word for six.',
      },
    ],
  },
  {
    id: 'science',
    name: 'Science',
    description: 'Atoms, cells, and the laws that run the universe.',
    icon: 'flask',
    questions: [
      {
        id: 's1',
        prompt: 'What is the chemical symbol for gold?',
        options: ['Go', 'Gd', 'Au', 'Ag'],
        answer: 2,
        explanation: 'Au comes from the Latin word “aurum”.',
      },
      {
        id: 's2',
        prompt: 'What part of the cell is known as its powerhouse?',
        options: ['Nucleus', 'Ribosome', 'Mitochondria', 'Golgi body'],
        answer: 2,
        explanation: 'Mitochondria produce most of the cell’s ATP energy.',
      },
      {
        id: 's3',
        prompt: 'Approximately how fast does light travel in a vacuum?',
        options: ['300,000 km/s', '150,000 km/s', '30,000 km/s', '1,000,000 km/s'],
        answer: 0,
        explanation: 'Light travels at about 299,792 kilometers per second.',
      },
      {
        id: 's4',
        prompt: 'Which gas do plants primarily absorb from the atmosphere?',
        options: ['Oxygen', 'Nitrogen', 'Carbon dioxide', 'Helium'],
        answer: 2,
        explanation: 'Plants use CO₂ during photosynthesis to make glucose.',
      },
      {
        id: 's5',
        prompt: 'What is the most abundant element in the universe?',
        options: ['Oxygen', 'Hydrogen', 'Carbon', 'Helium'],
        answer: 1,
        explanation: 'Hydrogen makes up roughly 74% of ordinary matter.',
      },
      {
        id: 's6',
        prompt: 'How many bones are in the adult human body?',
        options: ['186', '206', '226', '256'],
        answer: 1,
        explanation: 'Babies are born with around 300 bones that fuse over time.',
      },
      {
        id: 's7',
        prompt: 'What is the boiling point of water at sea level in Celsius?',
        options: ['90°C', '100°C', '110°C', '120°C'],
        answer: 1,
        explanation: 'At 1 atmosphere of pressure, water boils at 100°C.',
      },
      {
        id: 's8',
        prompt: 'Which scientist proposed the theory of general relativity?',
        options: ['Isaac Newton', 'Niels Bohr', 'Albert Einstein', 'Marie Curie'],
        answer: 2,
        explanation: 'Einstein published general relativity in 1915.',
      },
    ],
  },
  {
    id: 'history',
    name: 'History',
    description: 'Empires, inventions, and the moments that shaped us.',
    icon: 'landmark',
    questions: [
      {
        id: 'h1',
        prompt: 'In what year did humans first land on the Moon?',
        options: ['1965', '1969', '1972', '1975'],
        answer: 1,
        explanation: 'Apollo 11 landed on July 20, 1969.',
      },
      {
        id: 'h2',
        prompt: 'Who was the first emperor of Rome?',
        options: ['Julius Caesar', 'Nero', 'Augustus', 'Caligula'],
        answer: 2,
        explanation: 'Augustus became the first Roman emperor in 27 BC.',
      },
      {
        id: 'h3',
        prompt: 'Which civilization built Machu Picchu?',
        options: ['Aztec', 'Maya', 'Inca', 'Olmec'],
        answer: 2,
        explanation: 'The Inca built Machu Picchu in the 15th century.',
      },
      {
        id: 'h4',
        prompt: 'Who invented the movable-type printing press in Europe?',
        options: ['Leonardo da Vinci', 'Johannes Gutenberg', 'Galileo Galilei', 'Thomas Edison'],
        answer: 1,
        explanation: 'Gutenberg’s press, around 1440, revolutionized publishing.',
      },
      {
        id: 'h5',
        prompt: 'The Berlin Wall fell in which year?',
        options: ['1987', '1989', '1991', '1993'],
        answer: 1,
        explanation: 'The wall fell on November 9, 1989.',
      },
      {
        id: 'h6',
        prompt: 'Which ancient wonder was located in Alexandria?',
        options: ['Hanging Gardens', 'Colossus', 'The Lighthouse', 'Temple of Artemis'],
        answer: 2,
        explanation: 'The Lighthouse of Alexandria stood on the island of Pharos.',
      },
      {
        id: 'h7',
        prompt: 'Who was the first woman to win a Nobel Prize?',
        options: ['Rosalind Franklin', 'Marie Curie', 'Ada Lovelace', 'Florence Nightingale'],
        answer: 1,
        explanation: 'Marie Curie won the Nobel Prize in Physics in 1903.',
      },
      {
        id: 'h8',
        prompt: 'The Titanic sank during its maiden voyage in which year?',
        options: ['1905', '1912', '1918', '1923'],
        answer: 1,
        explanation: 'The Titanic struck an iceberg on April 15, 1912.',
      },
    ],
  },
  {
    id: 'geography',
    name: 'Geography',
    description: 'Capitals, continents, and the shape of the world.',
    icon: 'globe',
    questions: [
      {
        id: 'p1',
        prompt: 'What is the capital city of Australia?',
        options: ['Sydney', 'Melbourne', 'Canberra', 'Perth'],
        answer: 2,
        explanation: 'Canberra was purpose-built as a compromise capital.',
      },
      {
        id: 'p2',
        prompt: 'Which is the longest river in the world?',
        options: ['Amazon', 'Nile', 'Yangtze', 'Mississippi'],
        answer: 1,
        explanation: 'The Nile is about 6,650 km long, narrowly ahead of the Amazon.',
      },
      {
        id: 'p3',
        prompt: 'Which country has the largest land area?',
        options: ['Canada', 'China', 'United States', 'Russia'],
        answer: 3,
        explanation: 'Russia covers over 17 million square kilometers.',
      },
      {
        id: 'p4',
        prompt: 'Mount Everest sits on the border of Nepal and which country?',
        options: ['India', 'China', 'Bhutan', 'Pakistan'],
        answer: 1,
        explanation: 'Everest straddles Nepal and the Tibet region of China.',
      },
      {
        id: 'p5',
        prompt: 'What is the smallest country in the world by area?',
        options: ['Monaco', 'San Marino', 'Vatican City', 'Liechtenstein'],
        answer: 2,
        explanation: 'Vatican City is only about 0.44 square kilometers.',
      },
      {
        id: 'p6',
        prompt: 'Which desert is the largest hot desert on Earth?',
        options: ['Gobi', 'Kalahari', 'Sahara', 'Arabian'],
        answer: 2,
        explanation: 'The Sahara spans roughly 9 million square kilometers.',
      },
      {
        id: 'p7',
        prompt: 'How many continents are there on Earth?',
        options: ['5', '6', '7', '8'],
        answer: 2,
        explanation: 'Africa, Antarctica, Asia, Australia, Europe, North and South America.',
      },
      {
        id: 'p8',
        prompt: 'Which ocean is the largest?',
        options: ['Atlantic', 'Indian', 'Arctic', 'Pacific'],
        answer: 3,
        explanation: 'The Pacific covers about a third of Earth’s surface.',
      },
    ],
  },
]

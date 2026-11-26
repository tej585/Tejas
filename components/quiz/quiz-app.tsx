'use client'

import { useState } from 'react'
import { categories, type Category } from '@/lib/quiz-data'
import { CategorySelect } from './category-select'
import { QuizSession } from './quiz-session'
import { QuizResults, type AnswerRecord } from './quiz-results'

type Stage =
  | { name: 'select' }
  | { name: 'playing'; category: Category; round: number }
  | { name: 'results'; category: Category; answers: AnswerRecord[] }

export function QuizApp() {
  const [stage, setStage] = useState<Stage>({ name: 'select' })
  const [round, setRound] = useState(0)

  const startQuiz = (category: Category) => {
    const nextRound = round + 1
    setRound(nextRound)
    setStage({ name: 'playing', category, round: nextRound })
  }

  if (stage.name === 'playing') {
    return (
      <QuizSession
        key={stage.round}
        category={stage.category}
        onQuit={() => setStage({ name: 'select' })}
        onFinish={(answers) => setStage({ name: 'results', category: stage.category, answers })}
      />
    )
  }

  if (stage.name === 'results') {
    return (
      <QuizResults
        category={stage.category}
        answers={stage.answers}
        onRetry={() => startQuiz(stage.category)}
        onHome={() => setStage({ name: 'select' })}
      />
    )
  }

  return <CategorySelect categories={categories} onSelect={startQuiz} />
}
